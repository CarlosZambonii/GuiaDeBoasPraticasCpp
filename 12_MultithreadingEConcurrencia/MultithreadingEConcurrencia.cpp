#include <iostream>
#include <thread>
#include <vector>

void tarefa(int id) {
    std::cout << "Thread " << id << " iniciada.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " finalizada.\n";
}

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(tarefa, i + 1);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Todas as threads finalizaram.\n";
    return 0;
}
