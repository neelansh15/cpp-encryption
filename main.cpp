#include <iostream>
#include <fstream>

using namespace std;

class encryption{
    int key;
    char c;
    string input_file;

    public:
        void encrypt();
        void decrypt();

        encryption(string filename){
            input_file = filename;
        }
    
};

void encryption::encrypt(){
    cout << "Integer Key for encryption: " << endl;
    cin >> key;

    fstream fin, fout;

    fin.open(input_file, fstream::in);
    fout.open("encrypt.txt", fstream::out);

    while(fin >> noskipws >> c){
        int temp = (c + key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

void encryption::decrypt(){
    cout << "Integer Key for decryption: " << endl;
    cin >> key;

    fstream fin, fout;

    fin.open(input_file, fstream::in);
    fout.open("decrypt.txt", fstream::out);

    while(fin >> noskipws >> c){
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

int main(int argc, char **argv){
    
    cout << "Neelansh's Encryption Suite" << endl;

    string type = argv[1];
    string filename = argv[2];

    encryption enc(filename);

    if(type == "encrypt"){
        enc.encrypt();
    }
    else if (type == "decrypt"){
        enc.decrypt();
    }
    else{
        cout << "Invalid operation type, please enter either encrypt or decrupt followed by the file name" << endl;
    }

    return 0;
}

// Reference: https://www.geeksforgeeks.org/encrypt-and-decrypt-text-file-using-cpp/
