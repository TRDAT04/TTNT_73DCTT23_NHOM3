#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm mục tiêu f(x) = x^2
double objective_function(double x)
{
    return x * x;
}

// Đạo hàm của hàm mục tiêu f'(x) = 2x
double gradient(double x)
{
    return 2 * x;
}

// Hàm thực hiện thuật toán Gradient Descent
void gradient_descent(double initial_x,
                      double learning_rate,
                      int max_iterations,
                      double epsilon)
{
    double x = initial_x;
    double grad;
    int iteration = 0;

    printf("Bắt đầu Gradient Descent:\n");
    printf("Iteration\t x\t\t f(x)\t\t Gradient\n");
    printf("--------------------------------------------------------\n");

    do
    {
        // Tính giá trị hàm mục tiêu và gradient
        double y = objective_function(x);
        grad = gradient(x);

        // In thông tin của iteration hiện tại
        printf("%d\t\t %.6f\t %.6f\t %.6f\n",
               iteration, x, y, grad);

        // Cập nhật x theo công thức GD
        x = x - learning_rate * grad;

        iteration++;

    } while (fabs(grad) > epsilon && iteration < max_iterations);

    printf("--------------------------------------------------------\n");
    printf("Kết quả cuối cùng:\n");
    printf("x = %.6f\n", x);
    printf("f(x) = %.6f\n", objective_function(x));
    printf("Số vòng lặp: %d\n", iteration);
}

int main()
{
    // Thiết lập các tham số
    double initial_x = 2.0;     // Điểm khởi đầu
    double learning_rate = 0.1; // Tốc độ học
    int max_iterations = 100;   // Số vòng lặp tối đa
    double epsilon = 1e-6;      // Ngưỡng dừng (độ chính xác)

    // Chạy thuật toán
    gradient_descent(initial_x, learning_rate, max_iterations, epsilon);

    return 0;
}