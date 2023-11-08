/*
 * Author:Muxtorov Dilshod
 * Date:8.11.2023
 * Name:
 */

#include <iostream>
#include <vector>
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"


int main() {
    std::cout << "Task 1" << std::endl;
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.getTop() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element: " << stack.getTop() << std::endl;

    stack.pop();

    if (stack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }
    std::cout << "Task 2" << std::endl;
    int n;
    std::string brackets;
    
    std::cin >> n;
    std::cin >> brackets;
    
    if (isValidExpression(n, brackets)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << "Task 3" << std::endl;
    std::string expression;
    std::getline(std::cin, expression);
    
    int result = evaluateExpression(expression);
    
    std::cout << result << std::endl;
    std::cout << "Task 4" << std::endl;
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> stacks(N);
    std::vector<int> piles(N);

    for (int i = 0; i < N; i++) {
        int k;
        std::cin >> k;

        for (int j = 0; j < k; j++) {
            int type;
            std::cin >> type;
            stacks[i].push_back(type);
        }
    }

    bool solutionFound = true;

    for (int i = 0; i < N; i++) {
        if (stacks[i].empty()) {
            continue;
        }

        int topContainer = stacks[i].back();
        stacks[i].pop_back();

        if (topContainer != i + 1) {
            bool found = false;

            for (int j = 0; j < N; j++) {
                if (piles[j] == topContainer) {
                    piles[j] = i + 1;
                    found = true;
                    break;
                }
            }

            if (!found) {
                solutionFound = false;
                break;
            }
        }
    }

    if (solutionFound) {
        for (int i = 0; i < N; i++) {
            while (!stacks[i].empty()) {
                int container = stacks[i].back();
                stacks[i].pop_back();
                std::cout << i + 1 << " " << piles[i] << std::endl;
                piles[i] = container;
            }
        }
    } else {
        std::cout << 0 << std::endl;
    }

    std::cout << "Task 5" << std::endl;
    int N;
    std::cout << "Enter the number of disks: ";
    std::cin >> N;

    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
