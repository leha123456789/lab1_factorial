Лабораторная 1 по основам параллельных вычислений(факториал числа, многопоточность)

Описание
Программа вычисляет факториал заданного числа с использованием многопоточности

![image](https://github.com/leha123456789/lab1_factorial/assets/19330391/0bf290be-059c-40ec-8cf4-4ef6100cf373)

Результат работы программы

Сначала определяется число, для которого нужно вычислить факториал. В программе это переменная number, установленная на значение 20. Затем диапазон значений от 1 до number разбивается на части для распределения между потоками. 
Для вычисления факториала используются несколько потоков. Число потоков определяется переменной num_threads, которая изменяется в цикле от 1 до 32. Для каждого значения num_threads создаются соответствующее количество потоков. 
Каждый поток запускает функцию calculateFactorial, которая вычисляет факториал для своего диапазона значений. Эта функция использует переданный ей диапазон и вычисляет факториал для каждого числа в этом диапазоне. 
После создания и запуска всех потоков основной поток ожидает их завершения с помощью вызова join() для каждого потока. 
Каждый поток вычисляет свой факториал и сохраняет результат в векторе results. Затем основной поток объединяет результаты всех потоков, перемножая их, чтобы получить общий факториал числа. 
Для каждой итерации цикла измеряется время выполнения всех потоков и выводится в стандартный вывод. 
После завершения цикла по числу потоков программа анализирует время выполнения и определяет оптимальное количество потоков, которое дало наименьшее время выполнения. 
После выполнения всех итераций цикла и определения оптимального числа потоков программа выводит наименьшее время выполнения, оптимальное количество потоков и значение факториала числа.
