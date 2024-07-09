#import "../title_page_template.typ": title_page
#import "../layouts.typ": head1, head2, un_heading, indent

#set page(margin: 2cm)
#set text(size: 14pt, font: "New Computer Modern", kerning: false)
#set page(paper: "a4")
#set heading(numbering: "1.")
#set par(justify: true)
#set par(leading: 0.65em)
#set figure(supplement: [Рисунок])
#set figure.caption(separator: [ -- ])

#title_page(5, [Строки])

#un_heading([Оглавление])

#outline(
  title: none
)

#pagebreak()

#set page(numbering: "1")

#head1([= Условие задачи])

#par(
  [#indent Требуется выполнить два задания по обработке текста.]
)

#par(
  [#indent В первом задании для представления текста использовать ноль-терминированную строку языка C. Для управления строкой использовать функции файла заголовка (библиотека функций управления ноль-терминированной строкой) #raw("<string.h>"). ]
)

#par(
  [#indent Во втором задании использовать для представления текста строку класса #raw("<string>"). Для управления строкой использовать методы класса #raw("string").]
)

#indent Задание моего персонального варианта (№22):

#par(
  [#indent Даны два предложения. Вывести слова, общие для этих двух предложений. Если таких слов нет, то вывести сообщение об этом.]
)

#pagebreak()

#head1([= Описание алгоритма решения задачи])

#par(
  [#indent Первым делом для решения задачи нужно разбить оба предложения на отдельные слова (строки), а затем попарно их сравнить. Для этого можно воспользоваться алгоритмом перебора с вложенным циклом. Допустим, у нас есть 2 массива со словами (строками) длинами $n$ и $m$ соответственно. Запустим цикл от 0 до $n-1$ для первого массива, а внутри данного цикла запустим еще один от 0 до $m-1$ для второго массива (таким образом мы гарантируем однократное сравнение каждого слова первого массива с каждым словом второго массива). Далее просто сравним элементы каждой пары. Если элементы равны, то выведем любой из этих элементов на экран. Если среди элементов пар ни найдется ни одних равных, то выведем сообщение об этом. ]
)

#head1([= Реализация задания 1])

#head2([== Описание применяемых в реализации методов строки функций из библиотеки #raw("<string.h>")])

#par(
  [
    + #raw("strtok") -- поиск лексем строки по разделителям.
    + #raw("strlen") -- возврат длины строки.
    + #raw("strcpy") -- копирование содержимого строки.
    + #raw("strncpy") -- копирование $n$ первых символов строки.
    + #raw("strcat") -- конкатенация двух строк.
    + #raw("memcpy") -- копирование блока данных из строки.
  ]
)

#head2([== Код реализации задания 1])

#par([1. Код файла #raw("myString.h")])
#let c_str_h = read("../../src/work_5/null_terminated_string/headers/my_string.h")
#raw(c_str_h, lang: "cpp")

#par([2. Код файла #raw("myString.cpp")])
#let c_str_cpp = read("../../src/work_5/null_terminated_string/source/my_string.cpp")
#raw(c_str_cpp, lang: "cpp")

#par([3. Код файла #raw("main.cpp")])
#let c_str_main = read("../../src/work_5/null_terminated_string/main.cpp")
#raw(c_str_main, lang: "cpp")

#head2([== Время выполнения задачи варианта])

#par([Таблица 1 -- Таблица зависимости времени выполнения программы от объема входных данных])

#figure(
  table(
    columns: 3, 
    table.header(
      [Номер], [Объем входных данных, символы], [Время выполнения, мс]
    ),
    [1], [10], [2],
    [2], [100], [29], 
    [3], [500], [54],
    [4], [1000], [103]
  ),
)

#head2([== Тестирование])

#head2([=== Таблица с тестами])

#text(
  [Таблица 2 -- Таблица тестов для задания 1]
)

#figure(
  table(
    columns: 3,
    align: (center, left, center),
    table.header(
      [Номер], [Входные данные], [Ожидаемый вывод]
    ),
    [1], [Escape the society \ We live in society], [society],
    [2], [The quick brown fox jumps over the lazy dog \ A quick brown dog jumps over a lazy fox], [quick brown jumps over lazy]
  )
)

#pagebreak()

#head2([=== Результаты тестирования])

#figure(
  image(
    "images/test1_1.png", width: 80%
  ),
  caption: [Тест №1]
)

#figure(
  image(
    "images/test1_2.png", width: 80%
  ),
  caption: [Тест №2]
)

#pagebreak()

#head1([= Реализация задания 2])

#head2([== Описание применяемых в реализации методов строки функций из библиотеки #raw("<string>")])

#par(
  [
    + #raw("resize") -- изменение текущего размера строки
    + #raw("substr") -- возврат подстроки
    + #raw("insert") -- вставка подстроки
    + #raw("erase") -- удаление подстроки
    + #raw("find_first_of") -- возврат первого индекса любого из набора символов 
    + #raw("empty") -- проверка строки на пустоту
  ]
)

#head2([== Код реализации задания 2])

#par([1. Код файла #raw("myString.h")])
#let std_str_h = read("../../src/work_5/std_string/headers/my_string.h")
#raw(std_str_h, lang: "cpp")

#par([2. Код файла #raw("myString.cpp")])
#let std_str_cpp = read("../../src/work_5/std_string/source/my_string.cpp")
#raw(std_str_cpp, lang: "cpp")

#par([3. Код файла #raw("main.cpp")])
#let std_str_main = read("../../src/work_5/std_string/main.cpp")
#raw(std_str_main, lang: "cpp")

#head2([== Время выполнения задачи варианта])

#figure(
  table(
    columns: 3,
    table.header(
      [Номер], [Объем входных данных, символы], [Время выполнения, мс]
    ),
    [1], [10], [4],
    [2], [100], [32], 
    [3], [500], [57],
    [4], [1000], [122]
  ),
)

#head2([== Тестирование])

#head2([=== Таблица с тестами])

#par([Таблица 3 -- Таблица тестов для задания 2])

#figure(
  table(
    columns: 3,
    align: (center, left, center),
    table.header(
      [Номер], [Входные данные], [Ожидаемый вывод]
    ),
    [1], [Don't take my snacks, please \ Can you borrow me some cheaps?], [Общих слов нет],
    [2], [He has a decent problem to solve \ I am stuck on this problem], [problem]
  )
)

#pagebreak()

#head2([=== Результаты тестирования])

#figure(
  image(
    "images/test2_1.png", width: 80%
  ),
  caption: [Тест №1]
)

#figure(
  image(
    "images/test2_2.png", width: 80%
  ),
  caption: [Тест №2]
)

#head1([= Выводы])

#par(
  [#indent В результате выполнения работы были получены знания по выполнению операций над ноль-терминированной строкой, организации хранения строковых данных класса #raw("string") и использованию средств языка C++ для реализации алгоритмов обработки текстовых данных.]
)