#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> undoStack;
stack<string> redoStack;
string currentText;

void tambahteks(const string& text) {
    undoStack.push(currentText);
    while (!redoStack.empty()) redoStack.pop(); // Bersihkan stack redo
    currentText += text;
    cout << "Teks saat ini: " << currentText << endl;
}

void undo() {
    if (!undoStack.empty()) {
        redoStack.push(currentText);
        currentText = undoStack.top();
        undoStack.pop();
        cout << "Undo berhasil. Teks saat ini: " << currentText << endl;
    } else {
        cout << "Undo stack kosong. Tidak ada yang bisa di-undo." << endl;
    }
}

void redo() {
    if (!redoStack.empty()) {
        undoStack.push(currentText);
        currentText = redoStack.top();
        redoStack.pop();
        cout << "Redo berhasil. Teks saat ini: " << currentText << endl;
    } else {
        cout << "Redo stack kosong. Tidak ada yang bisa di-redo." << endl;
    }
}

bool isEmptyUndo() {
    return undoStack.empty();
}

bool isEmptyRedo() {
    return redoStack.empty();
}

void tampilkanMenu() {
    cout << "Pilih perintah yang ingin dijalankan:" << endl;
    cout << "1. Ketik" << endl;
    cout << "2. Undo" << endl;
    cout << "3. Redo" << endl;
    cout << "4. IsEmptyUndo" << endl;
    cout << "5. IsEmptyRedo" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukkan pilihan Anda (1-6): ";
}

int main() {
    int pilihan;
    string teks;

    while (true) {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan teks yang ingin diketik: ";
                cin.ignore();  // Membersihkan newline character dari buffer
                getline(cin, teks);
                tambahteks(teks);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                cout << (isEmptyUndo() ? "Undo stack kosong." : "Undo stack tidak kosong.") << endl;
                break;
            case 5:
                cout << (isEmptyRedo() ? "Redo stack kosong." : "Redo stack tidak kosong.") << endl;
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak dikenal. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

