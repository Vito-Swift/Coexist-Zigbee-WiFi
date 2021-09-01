//
// Created by Vito Wu on 2021/8/13.
//

#ifndef ZIGBEETESTBED_THREADSAFE_QUEUE_HH
#define ZIGBEETESTBED_THREADSAFE_QUEUE_HH

#include <queue>
#include <mutex>
#include <condition_variable>

#define VERBOSE 1

template<class T>
class Queue {
public:
    Queue() : q(), m(), c() {
        is_close = false;
        size = INT32_MAX;
    }

    ~Queue() {}

    void enqueue(T t) {
        std::lock_guard<std::mutex> lock(m);
        if (is_close)
            throw std::runtime_error("try to push into a closed queue!");
        if (q.size() > size) {
            q.pop();
        }
        q.push(t);
        c.notify_one();
    }

    bool dequeue(T &t) {
        std::unique_lock<std::mutex> lock(m);
        while (q.empty() && !is_close) {
            c.wait(lock);
        }
        if (is_close)
            return false;
        t = q.front();
        q.pop();
        return true;
    }

    void close() noexcept {
        std::lock_guard<std::mutex> lock(m);
        is_close = true;
        c.notify_all();
    }

    void open() noexcept {
        std::lock_guard<std::mutex> lock(m);
        is_close = false;
        c.notify_all();
    }

    void set_size(const unsigned int &s) {
        size = s;
    }

private:
    std::queue<T> q;
    unsigned int size;
    mutable std::mutex m;
    std::condition_variable c;
    bool is_close;
};

#endif //ZIGBEETESTBED_THREADSAFE_QUEUE_HH
