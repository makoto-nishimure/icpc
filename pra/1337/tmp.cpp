#include <iostream>

struct data_t {
    int key1;
    int key2;
    float value;
};

bool cmp(const data_t& left, const data_t& right) {
    return (left.key1 == right.key1) ? (left.key2 < right.key2) : (left.key1 < right.key1);
}

int main(){
    struct data_t data[] = {{0, 1, 1}, {4, 5, 2}, {5, 2, 3}, {2, 4, 4}, {2, 0, 5}, {2, 3, 6}};
    std::sort(data, data + 6, cmp);
    for (int i = 0; i < 6; i++)
        std::cout << "{" << data[i].key1 
                  << "," << data[i].key2 
                  << "," << data[i].value << "}"
                  << std::endl;

    return 0;
}
