#ifndef FIXED_SIZE_QUEUE
#define FIXED_SIZE_QUEUE

#include <iostream>
#include <deque>
#define SAVE_FRAME_NUM 2

template <typename T>

class FixedSizeQueue {
private:
    std::deque<T> data;
    const size_t maxSize = SAVE_FRAME_NUM;

public:
    FixedSizeQueue() {}

    void push(T& value) {
        if (data.size() >= maxSize) {
            data.pop_front(); // 큐의 크기가 최대 크기에 도달하면 가장 오래된 값을 제거
        }
        data.push_back(value);
    }
    
    void print() {
        std::cout << "최근 " << data.size() << "개 데이터: ";
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    const std::deque<T>& getData() const {
        return data;
    }

    int getMaxSize(){
        return maxSize;
    }
};

#endif