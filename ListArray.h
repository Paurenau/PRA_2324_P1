#ifndef LISTARRAY_H
#define LISTARRAY_H

template <typename T> 
class ListArray {
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;

    public:
        ListArray(){
            arr = new T[MINSIZE];
            n = 0;
            max = MINSIZE;

        }

        ~ListArray(){
            delete[] arr;
        }

        T operator[](int pos){
            if(pos < 0 || pos > size){
                throw std::out_of_range;
            }

            return arr[pos];
        }

        
};

#endif