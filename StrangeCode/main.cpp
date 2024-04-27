#include <vector>
#include <iostream>

template <typename T = char> size_t CreateArrayAtMemory(void*, size_t bs)
{
    return bs * sizeof(T);
}

template <typename T = char, typename ... Args>
size_t CreateArrayAtMemory(void* p, size_t bs, Args ... args)
{
    size_t R = 0;
    size_t PS = sizeof(void*);
    char* P = (char*)p;
    char* P0 = (char*)p;

    size_t BytesForAllPointers = bs * PS;
    R = BytesForAllPointers;

    char* pos = P0 + BytesForAllPointers;
    for (size_t i = 0; i < bs; i++)
    {
        char** pp = (char**)P;
        if (p)
            *pp = pos;
        size_t RLD = CreateArrayAtMemory<T>(p ? pos : nullptr, args ...);
        P += PS;
        R += RLD;
        pos += RLD;
    }
    return R;
}

int main(){
    int j = 0x21;
    size_t n2 = CreateArrayAtMemory<short>(nullptr,2,3);
    vector<char> a2(n2);
    short** f2 = (short**)a2.data();
    CreateArrayAtMemory<short>(f2,2,3);
    for (int i1 = 0; i1 < 2; i1++)
    {
       for (int i2 = 0; i2 < 3; i2++)
       {
          f2[i1][i2] = j++;
      }
    }
    // Dump
    for (int i1 = 0; i1 < 2; i1++)
    {
       for (int i2 = 0; i2 < 3; i2++)
       {
           std::cout << (int)f2[i1][i2] << " ";
       }
    }
    std::cout << std::endl << n2 << " bytes used " << std::endl;
    std::cout << std::endl;

    return 0;
}