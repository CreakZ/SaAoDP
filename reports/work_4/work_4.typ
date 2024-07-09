#import "../title_page_template.typ": title_page
#import "../layouts.typ": un_heading, head1, indent, head2
#set page(
  paper: "a4", 
  margin: (left: 2cm, right: 2cm, top: 2cm, bottom: 2cm)
)
#set heading(numbering: "1.1.1.")
#set text(font: "New Computer Modern", size: 14pt, kerning: false)
#set figure(supplement: [Рисунок])
#set figure.caption(separator: [ -- ])

#show table: it => {align(center, it)}

#title_page(4, [Многомерные массивы])

#un_heading([Оглавление])

#outline(
  title: none,
  indent: none
)

#pagebreak()

#set page(numbering: "1")

#head1([= Условие задачи])

#indent Задания моего персонального варианта (№22):

#let task(num, desc) = {
  par(justify: true, [#indent *#num*. #desc])
}

#task([Задание 1], [Разработать АТД задачи варианта по управлению многомерными данными и реализовать на статическом многомерном массиве.])

#task([Задание 2], [Разработать АТД задачи варианта по управлению многомерными данными и реализовать на динамическом многомерном массиве.])

#task([Задание 3], [Разработать программу решения задачи варианта по управлению многомерными данными и реализовать с применением шаблона #raw("<vector>", lang: "cpp") библиотеки STL.])

#head1([= Постановка задачи])

#task([Задания 1 и 2], [Дана квадратная матрица. Найти определитель данной матрицы методом Гаусса.])

#task([Задание 3], [На плоскости задано множество точек с целочисленными координатами. Необходимо найти количество отрезков, обладающих следующими свойствами: \
#indent 1. Оба конца отрезка принадлежат заданному множеству; \
#indent 2. Ни один конец отрезка не лежит на осях координат; \
#indent 3. Отрезок пересекается ровно с одной осью координат. \
#indent Напишите эффективную по времени и по используемой памяти программу для решения этой задачи.])

#pagebreak()

#head1([= Математическая модель])

#head2([== Задания 1 и 2.])

#indent Допустим, у нас есть матрица следующего вида: \

#align(
  center, [
    $ A = 
    mat(
      1, 3, 3, 7;
      3, 4, 3, 4;
      5, 6, 7, 8;
      6, 9, 6, 9;
    ) $
  ]
)

#par(justify: true, [#indent Согласно методу Гаусса, для вычисления определителя нужно сначала привести матрицу к треугольному виду, а затем найти произведение элементов на главной диагонали. Значение полученного произведения (назовем его $Delta$) и будет определителем  матрицы. \

#indent Приведем матрицу $A$ к диагональному виду:])

#align(center, [$ Delta = 
mat(
  1, 3, 3, 7;
  3, 4, 3, 4;
  5, 6, 7, 8;
  6, 9, 6, 9;
  delim: "|"
) = 
mat(
  1, 3, 3, 7;
  0, -5, -6, -17;
  0, -9, -8, -27;
  0, -9, -12, -33;
  delim: "|"
) = 
mat(
  1, 3, 3, 7;
  0, -5, -6, -17;
  0, 0, 14/5, 18/5;
  0, 0, -6/5, -12/5;
  delim: "|"
) =
mat(
  1, 3, 3, 7;
  0, -5, -6, -17;
  0, 0, 14/5, 18/5;
  0, 0, 0, -6/7;
  delim: "|"
) $])

#indent В данном случае $Delta = 1 times (-5) times 14/5 times (-6/7) = 12 $.

#par(justify: true, [#indent Как видно из приведенного примера, приведение к треугольному виду представляет из себя $quote.angle.l.double$обнуление$quote.angle.r.double$ элементов, стоящих под главной диагональю. Для того, чтобы добиться этого в общем случае, нужно из текущей строки вычесть строку, располагающуюся выше текущей и умноженную на некоторый коэффициент (назовем его $lambda$). \
])

#indent В нашем примере $lambda_1 = a_21/a_11 = 3$, 
$lambda_2 = a_32/a_21 = 9/5$, $lambda_3 = a_43/a_32 = -6/14$.

#indent Видно, что общем случае для $n$-й строки ($n > 1, n in NN$) получается: \
#align(center, [$ lambda_n = a_((n+1)n) / a_(n n) $])

#indent Тогда элемент $n$-й строки $m$-го столбца будет равен: $ a_(n m) = a_(n m) - lambda a_((n-1) m) $

#indent Определитель же в общем виде будет находиться по следующей формуле: $ Delta = attach(Pi, t: n, b: 1) a_(n n) $

#head2([== Задание 3])

#par(justify: true, [
  #indent Построим математическую модель задачи на основе рассмотрения примера (см. рис. 1).

  #figure(
    image("images/plot.svg", width: 60%),
    caption: [Пример взаимного расположения точек на координатой плоскости]
  )

  #indent Как видно из рис. 1, точки, лежащие в соседних квадрантах, образуют отрезки, подходящие под критерии задачи ($A B$, $A C$, $B D$, $C D$), в то время как точки, лежащие в противолежащих квадрантах, таковых отрезков не образуют ($A D$, $B C$). Действительно, среди соответственных координат точек подходящих отрезков произведение ровно одной пары будет меньше нуля (например, для точек $A$ и $B:$ $y_A times y_B = 2 times (-3) = -6 < 0$, но $x_A times x_B = 2 times 5 = 10 > 0$), а для прочих отрезков произведение обеих пар будет одновременно либо больше, либо меньше нуля. #linebreak()
  #indent Отсюда получим следующую функцию:
  $ F(x_1, x_2, y_1, y_2) = (x_1 times x_2 < 0) plus.circle (y_1 times y_2 < 0), $ #indent где $x_1, x_2, y_1, y_2$ -- координаты точек отрезка. #linebreak()
  #indent Значение функции $F$ для отрезков, пересекающих ровно одну ось координат, всегда будет равно 1, а для прочих -- 0.
])

#pagebreak()

#head1([= АТД задачи])

#head2([== АТД для заданий 1 и 2])

#let tab(theme) = {
  set par(first-line-indent: 1.25cm, hanging-indent: 1.25cm)
  text([#theme #linebreak()])
}

#let method(num, head, pre, post, header) = {
  par(hanging-indent: 1.25cm, first-line-indent: 1.25cm, [
    #num #head #linebreak()
    Предусловие: #pre #linebreak()
    Постусловие: #post #linebreak()
    #align(left, [Заголовок: #header #linebreak()])
  ])
}

#par(justify: true, [АТД matrix \ { \
    #tab([_Данные_ (описание свойств структуры данных задачи)])
    #tab([MAX_SIZE - максимальная размерность матрицы])
    #tab([size - размерность текущего массива])
    #tab([array - двумерный массив, содержащий действительные числа])
    #tab([_Операции_ (объявления операций)])

    #method(
      [1.], 
      [Метод, осуществляющий заполнение с клавиатуры], 
      [array, size], 
      [array, заполненный действительными числами],
      [#raw("fillManually()")]
    )

    #method(
      [2.], 
      [Метод, заполняющий массив случайными   значениями], 
      [array, size], 
      [массив array, заполненный случайными значениями], 
      [#raw("fillRandomly()")]
    )

    #method(
      [3.], 
      [Метод, осуществляющий вывод текущих значений массива], 
      [array, size],
      [выведенные через пробел элементы массива],
      [#raw("print()")]
    )

    #method(
      [4.],
      [Метод, возвращающий значение определителя матрицы],
      [array, size],
      [действительное число - значение определителя матрицы],
      [#raw("det()")])
  }
])

#pagebreak()

#head2([== АТД для задания 3])

#par(justify: true, [АТД Set \ { \
    #tab([_Данные_ (описание свойств структуры данных задачи)])
    #tab([points - вектор, содержащий пары целочисленных значений (координаты точки)])
    
    #method([1.], 
    [Метод, осуществляющий заполнение с клавиатуры], 
    [array, size], 
    [array, заполненный действительными числами],
    [#raw("fillManually()")]
    )

    #method([2.], 
    [Метод, заполняющий массив случайными значениями], 
    [array, size], 
    [массив array, заполненный случайными значениями], 
    [#raw("fillRandomly()")]
    )

    #method([3.], 
    [Метод, осуществляющий вывод текущих значений массива], 
    [array, size],
    [выведенные через пробел элементы массива],
    [#raw("print()")]
    )

    #method([4.],
    [Метод, возвращающий #raw("true"), если хотя бы одна точка отрезка лежит на осях координат, иначе #raw("false")],
    [координаты точек концов отрезка],
    [#raw("true")/#raw("false")],
    [#raw("onAxis(std::pair<int, int>& point1, std::pair<int, int>& point2)")])

    #method([5.],
    [Метод, возвращающий #raw("true"), если отрезок пересекает ровно одну ось координат, иначе #raw("false")],
    [координаты конца точек отрезка], 
    [#raw("true")/#raw("false")],
    [#raw("singleAxisIntersection(std::pair<int, int>& point1, std::pair<int, int>& point2"))])
    

    #method([6.],
    [Метод, возращающий случайно сгенерированное целое число в диапазоне [-100, 100]],
    [_сильно зависит от конкретного языка программирования_], 
    [целое число из диапазона [-100, 100]],
    [#raw("generate(std::uniform_int_distribution<>& dis, std::mt19937& generator)")]
    )

    #method([7.],
    [Метод, возвращающий количество отрезков, удовлетворяющих условию задачи 3],
    [points],
    [целое число - количество отрезков],
    [#raw("validSegments()")])
  }
])

#head1([= Разработка и реализация задачи])

#head2([== Код программы])

#head2([=== Задание 1])

#text([1. Код файла #raw("matrixStatic.h") #linebreak()])
#let static_h = read("../../src/work_4/static_array/headers/matrix_static_array.h")
#raw(static_h, lang: "cpp")

#text([2. Код файла #raw("matrixStatic.cpp") #linebreak()])
#let static_cpp = read("../../src/work_4/static_array/source/matrix_static_array.cpp")
#raw(static_cpp, lang: "cpp")

#text([3. Код файла #raw("main.cpp") #linebreak()])
#let static_main = read("../../src/work_4/static_array/main.cpp")
#raw(static_main, lang: "cpp")

#head2([=== Задание 2])

#text([1. Код файла #raw("matrixDynamic.h") #linebreak()])
#let dynamic_h = read("../../src/work_4/dynamic_array/headers/matrix_dynamic_array.h")
#raw(dynamic_h, lang: "cpp")

#text([2. Код файла #raw("matrixDynamic.cpp") #linebreak()])
#let dynamic_cpp = read("../../src/work_4/dynamic_array/source/matrix_dynamic_array.cpp")
#raw(dynamic_cpp, lang: "cpp")

#text([3. Код файла #raw("main.cpp") #linebreak()])
#let dynamic_main = read("../../src/work_4/dynamic_array/main.cpp")
#raw(dynamic_main, lang: "cpp")

#head2([=== Задание 3])

#text([1. Код файла #raw("matrixVector.h")])
#let vector_h = read("../../src/work_4/vector/headers/matrix_vector.h")
#raw(vector_h, lang: "cpp")

#text([2. Код файла #raw("matrixVector.cpp")])
#let vector_cpp = read("../../src/work_4/vector/source/matrix_vector.cpp")
#raw(vector_cpp, lang: "cpp")

#text([3. Код файла #raw("main.cpp")])
#let vector_main = read("../../src/work_4/vector/main.cpp")
#raw(vector_main, lang: "cpp")

#head2([== Набор тестов])

#head2([=== Задания 1 и 2])

Таблица 1 -- Таблица тестов для заданий 1 и 2

#table(
  columns: 3,
  align: (center, center, center),
  table.header(
    [Номер], [Входные данные], [Ожидаемые выходные данные]
  ),
  [1], [
    size = 3 \
    array = {{1, 2, 3}, \ {4, 5, 6}, {7, 8, 9}}
  ], [0],
  [2], [
    size = 4 \
    array = {{1, 3, 3, 7}, {3, 4, 3, 4}, {5, 6, 7, 8}, {6, 9, 6, 9}}
  ], [18]
)

#head2([=== Задание 3])

Таблица 2 -- Таблица тестов для задания 3

#table(
  columns: 3,
  align: (center, center, center),
  table.header(
    [Номер], [Входные данные], [Ожидаемые выходные данные]
  ),
  [1], [points = {{1,2}, {3,4}, {5,-2}, {-3,-5}}], [3],
  [2], [points = {{1,0}, {0,1}, {0,0}, {6,9}}], [0]
)

#pagebreak()

#head2([== Результаты тестирования])

#figure(
  image("images/test12_1.png", width: 60%),
  caption: [Результаты тестирования теста №1 для заданий 1 и 2]
)

#figure(
  image("images/test12_2.png", width: 60%),
  caption: [Результаты тестирования теста №2 для заданий 1 и 2]
)

#figure(
  image("images/test3_1.png", width: 60%),
  caption: [Результаты тестирования теста №1 для задания 3]
)

#figure(
  image("images/test3_1.png", width: 60%),
  caption: [Результаты тестирования теста №2 для задания 3]
)

#head1([= Вывод])

#par(first-line-indent: 1.25cm, justify: true, 
[#indent В результате работе были получены навыки по определению многомерного статического и динамического массивов в программе, их представлению в оперативной памяти, определению структуры данных для хранения данных задачи и ее наиболее оптимальной реализации, а также разработке алгоритмов операций на многомерном (двумерном массиве) в соответствии с задачей.]
)