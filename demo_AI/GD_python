import numpy as np
import matplotlib.pyplot as plt

def gradient_descent(initial_x, learning_rate, n_iterations, gradient_func):
        x = initial_x
        x_history = [x]
        y_history = [objective_function(x)]

        for i in range(n_iterations):
            grad = gradient_func(x)
            x = x - learning_rate * grad
            x_history.append(x)
            y_history.append(objective_function(x))

            if np.abs(grad) < 1e-6:
                break

        return np.array(x_history), np.array(y_history)

def objective_function(x):
        return x**2

def gradient(x):
        return 2*x

    # Thực hiện GD
initial_x = 2.0
learning_rate = 0.1
n_iterations = 50

x_history, y_history = gradient_descent(initial_x, learning_rate, n_iterations, gradient)

    # Vẽ đồ thị minh họa
x = np.linspace(-2, 2, 100)
y = objective_function(x)

plt.figure(figsize=(10, 6))
plt.plot(x, y, 'b-', label='f(x) = x^2')
plt.plot(x_history, y_history, 'ro-', label='GD path')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Gradient Descent Optimization')
plt.legend()
plt.grid(True)
plt.show()
