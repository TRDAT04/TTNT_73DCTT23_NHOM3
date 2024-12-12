#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Hàm tạo số ngẫu nhiên trong khoảng [0,1]
double random_double()
{
    return (double)rand() / RAND_MAX;
}

// Hàm tạo trạng thái lân cận (ví dụ cho bài toán tối ưu hàm 1 biến)
double generate_neighbor(double current_state, double step_size)
{
    return current_state + (random_double() * 2 - 1) * step_size;
}

// Hàm mục tiêu (ví dụ: f(x) = x^2)
double objective_function(double x)
{
    return x * x;
}

// Thuật toán Simulated Annealing
double simulated_annealing(
    double initial_state,
    double initial_temp,
    double cooling_rate,
    double min_temp,
    double step_size,
    int max_iterations)
{
    double current_state = initial_state;
    double current_energy = objective_function(current_state);
    double best_state = current_state;
    double best_energy = current_energy;
    double temperature = initial_temp;

    srand(time(NULL)); // Khởi tạo seed cho random

    int iteration = 0;
    while (temperature > min_temp && iteration < max_iterations)
    {
        // Tạo trạng thái lân cận
        double neighbor_state = generate_neighbor(current_state, step_size);
        double neighbor_energy = objective_function(neighbor_state);

        // Tính delta energy
        double delta_energy = neighbor_energy - current_energy;

        // Quyết định chấp nhận trạng thái mới
        if (delta_energy < 0 ||
            random_double() < exp(-delta_energy / temperature))
        {
            current_state = neighbor_state;
            current_energy = neighbor_energy;

            // Cập nhật trạng thái tốt nhất nếu cần
            if (current_energy < best_energy)
            {
                best_state = current_state;
                best_energy = current_energy;
            }
        }

        // Giảm nhiệt độ
        temperature *= cooling_rate;
        iteration++;

        // In thông tin tiến trình (tùy chọn)
        if (iteration % 100 == 0)
        {
            printf("Iteration %d: T = %.6f, E = %.6f\n",
                   iteration, temperature, current_energy);
        }
    }

    return best_state;
}

int main()
{
    // Các tham số của thuật toán
    double initial_state = 10.0; // Trạng thái ban đầu
    double initial_temp = 100.0; // Nhiệt độ ban đầu
    double cooling_rate = 0.95;  // Tốc độ làm lạnh
    double min_temp = 0.01;      // Nhiệt độ dừng
    double step_size = 0.1;      // Kích thước bước nhảy
    int max_iterations = 1000;   // Số lần lặp tối đa

    // Chạy thuật toán
    double result = simulated_annealing(
        initial_state,
        initial_temp,
        cooling_rate,
        min_temp,
        step_size,
        max_iterations);

    printf("Best solution found: x = %.6f\n", result);
    printf("Objective value: f(x) = %.6f\n", objective_function(result));

    return 0;
}