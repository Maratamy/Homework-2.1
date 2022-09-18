#include <iostream>
#include <fstream>
using namespace std;

class RationalNumbers {
private:
    int lenght;
    double* arr;
public:
    
    RationalNumbers(int ArraySize = 0): arr(0), lenght(0) {
        if (ArraySize > 0) {
            arr = new double[ArraySize];
            lenght = ArraySize;
        }
    }

    RationalNumbers(const RationalNumbers& temp) : arr(0), lenght(0)
    {
        if (temp.lenght > 0) arr = new double[temp.lenght];
        if (arr) {
            lenght = temp.lenght;
            for (int i = 0; i < lenght; i++) { arr[i] = temp.arr[i]; }
        }
    }
    
    int Get_Size() {
        return lenght;
    }
    double& operator[](int index) {
        return arr[index];
    }
     double operator[](int index) const { 
        return arr[index];
    }
    
     void insert(double value) {
         double* Temp_target = new double[lenght + 1];
         int index = 0;
         for (; index < lenght; index++) {
             Temp_target[index] = arr[index];
         }
         Temp_target[index] = value;
         delete[] arr;
         lenght++;
         arr = Temp_target;
     }

    void erase(int start_index, int finish_index){
        int index = 0;
        double*  Temp_target = new double[lenght-(finish_index - start_index + 1)];
         for (; index < start_index; index++) {
             
             Temp_target[index] = arr[index];
             
         }
         for (int i = finish_index+1; i < lenght; i++) {
             Temp_target[index] = arr[i];
             index++;
         }
         delete[] arr;
         lenght = lenght - (finish_index - start_index + 1);
         arr = Temp_target;
         
         
     }

    ~RationalNumbers() {
         delete[] arr;
     }
};
int gg = 0;
void txt_input(RationalNumbers input, ifstream &File) {

    File.open("inputFile.txt");
    if (!File.is_open()) {
        cout << "File Error! File not found! Check file!" << endl;
    }
    double Buffer;
    char InputStr[80];

    while (File) {

        File >> InputStr;
        cout << InputStr << endl;
        if (strcmp(InputStr, "\0")) {
            Buffer = atof(InputStr);
            input.insert(Buffer);
        }
    }
    File.close();
}

void txt_output(RationalNumbers out, ofstream &o_file) {
    string f = "output.txt";
    o_file.open("output.txt", ofstream::app);
    for (int i = 0; i < out.Get_Size(); i++)
    {
        o_file << out[i] <<" ";
    }
    o_file << "\n";
    o_file.close();
}

int main()
{   ifstream File;
    
    RationalNumbers S1(0);
   // txt_input(S1, File);
   File.open("inputFile.txt");
    if (!File.is_open()) {
        cout << "File Error! File not found! Check file!" << endl;
    }
    int Buffer;
    char InputStr[80];
    while (File) {
        File >> InputStr;
        if (strcmp(InputStr, "\0")) {
            Buffer = atof(InputStr);
            S1.insert(Buffer);
        }
    }
    ofstream o_file;
    
    txt_output(S1, o_file);

    cout << endl; 
    S1.insert(8218);
    txt_output(S1, o_file);
    cout << S1.Get_Size() << endl;
    S1.erase(1, 2);
    txt_output(S1, o_file);

    return 0;
}