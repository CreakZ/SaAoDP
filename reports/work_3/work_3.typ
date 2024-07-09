#import "../title_page_template.typ": title_page
#import "../layouts.typ": indent
#set text(size: 14pt, font: "New Computer Modern")
#set heading(numbering: "1.1.1.")
#set page(
  paper: "a4", 
  margin: (left: 2cm, right: 2cm, top: 2cm, bottom: 2cm)
)

#title_page(3, [Абстрактный тип данных и его реализация на одномерном динамическом массиве и векторе])

#align(
  text("Оглавление", size: 14pt),
  center
)

#outline(
  title: none,
)

#pagebreak()

#set page(numbering: "1")

#align(
  center,
  text([= Отчет по заданию 1])
)

#align(
  center,
  text([== Условие задачи])
)

#par(
  first-line-indent: 1.25cm, 
  justify: true, [
  #indent Реализовать АТД задачи, разработанное в практической работе 1, используя для представления значений множества динамический массив. Выполнить реализацию АТД задачи на динамическом массиве. Для управления динамической памятью использовать функции файла заголовка stdlib.h: malloc, free, realloc.
])

#align(
  center,
  text([== АТД задачи])
)

#text([
  #indent Сформировать новый массив из чисел исходного, которые делятся на каждую цифру числа.
])

#align(
  center,
  text([== Текст АТД с операциями варианта ])
)

#text([
  АТД #raw("myDynArray") \
  { \
    _Данные_ (описание свойств структуры данных задачи): \
    n - количество элементов массива \
    m - количество элементов массива для дополнительного задания \
    arr - список элементов массива \
    _Операции_ (объявления операций): \
    - Метод, осуществляющий вывод текущих значений множества \
    Предусловие: нет \
    Постусловие: выведенные через пробел элементы множества \

    Заголовок: #raw("printElements()") \
    - Метод, осуществляющий заполнение массива вручную – с клавиатуры \
    Предусловие: нет \
    Постусловие: массив, заполненный значениями, введенными с клавиатуры \
    Заголовок: #raw("fillManually()") \

    - Метод, осуществляющий заполнение массива случайными значениями \
    Предусловие: нет \
    Постусловие: массив, заполненный случайными значениями \
    Заголовок: #raw("fillRandomly()") \

    - Метод, возвращающий индекс первого элемента, делящегося на каждую из своих цифр. В случае отсутствия такового элемента возвращается -1 \
    Предусловие: нет \
    Постусловие: число – индекс первого элемента, нацело делящегося на каждую из своих цифр \
    Заголовок: #raw("getIndex()")

    - Метод осуществляющий вставку элемента newElem на позицию с индексом pos \
    Предусловие: pos – индекс элемента, на место которого требуется вставить новый элемент, newElem – значение нового элемента \
    Постусловие: массив arr длиной n+1 со вставленным элементом newElem на позиции pos \
    Заголовок: #raw("insert(int pos, int newElem)") \

    - Метод, осуществляющий вставку нового элемента newElem после элемента с индексом getIndex(). Если getIndex() = -1, вставка производится в начало массива \
    Предусловие: newElem – значение нового элемента \
    Постусловие: массив arr длиной n+1 со вставленным элементом newElem на позиции getIndex() + 1 \
    Заголовок: #raw("getIndexInsert(int newElem)")

    - Метод, осуществляющий удаление из массива всех элементов, нацело делящихся на 3 \
    Предусловие: нет \
    Постусловие: измененный массив arr, содержащий элементы, не делящихся нацело на 3 \
    Заголовок: #raw("deleteMultiplesOfThree()") \

    _Дополнительные операции:_
    - Метод, формирующий новый массив из чисел исходного, которые делятся на каждую цифру числа \
    Предусловие: нет \
    Постусловие: новый массив, содержащий только числа исходного массива, нацело делящиеся на каждую из своих цифр \
    Заголовок: #raw("newArray()") \
  }
])


#pagebreak()


#align(
  center, [
    #text([== Разработка программы])
  ]
)

#text([=== Реализация данных АТД])


==== Код файла #raw("myArray.h")
#let dynArrH = read("../../src/work_3/dynamic_array/headers/my_dynamic_array.h")
#raw(dynArrH, lang: "cpp")

==== Код файла #raw("myArray.cpp")
#let dynArrCPP = read("../../src/work_3/dynamic_array/source/my_dynamic_array.cpp")
#raw(dynArrCPP, lang: "cpp")

==== Код файла #raw("main.cpp")
#par([_Комментарий: в данном файле показан пример работы программы для теста №1_])
#let dynArrMain = read("../../src/work_3/dynamic_array/main.cpp")
#raw(dynArrMain, lang: "cpp")

#text([=== Алгоритм дополнительной операции варианта])

#par([
  1. Вспомогательная функция, возвращающая #raw("true") в случае, если переданное в нее в качестве параметра число #raw("num") нацело делится на каждую из своих цифр, иначе #raw("false").
  Предусловие: целочисленная переменная #raw("num") \
  Постусловие: #raw("true/false") \
  Заголовок: #raw("dividesByAllDigits(int num)")
])

#text([
  Таблица 1 -- Алгоритм вспомогательной функции #raw("dividesByAllDigits(int num)")
])

#align(
  center, [
    #let tab = h(0.5cm)

    #table(
    columns: 2,
    align: (center, left),
    table.header(
      [Номер], [Инструкция]
    ),
    [1], [if num = 0 then],
    [2], [#tab return false],
    [3], [endIf],
    [4], [temp $<-$ num],
    [5], [while temp > 0 do],
    [6], [#tab digit $<-$ temp $mod$ 10],
    [7], [#tab if digit = 0 $or$ num $mod$ digit $eq.not$ 0],
    [8], [#(tab * 2)return false],
    [9], [#tab endIf],
    [10], [#tab temp $<-$ temp $mod$ 10],
    [11], [od],
    [12], [return true]
  )
  ]
)

#text([
  2. Основной метод \
  Таблица 2 -- Алгоритм метода #raw("newArray()")
])

#align(
  center, 
  [
    #let tab = h(0.5cm)

    #table(
      
      columns: 2,
      align: (center, left),
      table.header(
        [Номер], [Инструкция]
      ),
      [1], [newArray $<-$ #raw("[]")],
      [2], [size $<-$ 0], 
      [3], [for i $<-$ 0 to $n - 1$ do],
      [4], [#tab if dividesByAllDigits(arr[$i$])],
      [5], [#(tab * 2) \// TODO],
      [6], [#(tab * 2) newArray[$"size" - 1$] $<-$ arr[$i$]],
      [7], [#tab endIf],
      [8], [od],
      [9], [n $<-$ size],
      [10], [arr $<-$ newArray]
    )
  ]
)

#text([=== Таблицы тестов тестирования дополнительной операции варианта])

#text([
  Таблица 3 -- Таблица тестов для тестирования дополнительной операции варианта
])

#align(
  center,
  [
    #table(
      columns: 3,
      align: (center, left, left),
      table.header(
        [Номер], [Входные данные], [Результат работы]
      ),
      [1], [
        n = 6 \ 
        arr = {12, 43, 11, 99, 0, 7}
      ],
      [
        n = 4 \
        arr = {12, 11, 99, 7}
      ],
      [2], 
      [
        n = 4 \
        arr = {13, 17, 23, 29}
      ],
      [
        n = 0 \
        Ошибка: массив пуст!
      ]
    )
  ]
)

#text([=== Скрины результатов тестирования])

#align(
  left, [
    #text([
      Тест 1. 
    ])

    #image("images/test_1_1.png", width: 80%)

    #pagebreak()
    
    #text([
      Тест 2. 
    ])

    #image("images/test_1_2.png", width: 80%)
  ]
)


#align(
  center,
  text([= Отчет по заданию 2])
)

#align(
  center,
  text([== Коды функций операций вставки, удаления, формирования нового множества заданий 1 и 2, представленные в таблице])
)

#table(
  columns: 3,
  align: horizon,
  table.header(
    [Операция], [Коды функций задания 1], [Коды функций задания 2]
  ),
  [Вставить элемент], 
  [
    #set text(size: 10pt)
    #let insert = read("data/insert_1.txt")
    #raw(insert, lang: "cpp")
  ], 
  table.cell(
    align: top,
    [
      #set text(size: 10pt)
      #let insert = read("data/insert_2.txt")
      #raw(insert, lang: "cpp")
    ]
  ),
  [Удалить элемент], 
  table.cell(
    align: top,
    [
      #set text(size: 10pt)
      #let erase = read("data/erase_1.txt")
      #raw(erase, lang: "cpp")
    ]
  ), 
  table.cell(
    align: top,
    [
      #set text(size: 10pt)
      #let erase = read("data/erase_2.txt")
      #raw(erase, lang: "cpp")
    ]
  ),
  [Формирование нового множества], 
  table.cell(
    align: top,
    [
      #set text(size: 10pt)
      #let newArr = read("data/newArray_1.txt")
      #raw(newArr, lang: "cpp")
    ]
  ), 
  table.cell(
    align: top,
    [
      #set text(size: 10pt)
      #let newArr = read("data/newArray_2.txt")
      #raw(newArr, lang: "cpp")
    ]
  )
)

#align(
  center, [
    #text([== Код проекта])
  ]
)

#text([=== Код файла #raw("myArray.h")])
#let vector = read("../../src/work_3/vector/headers/my_vector.h")
#raw(vector, lang: "cpp")

#text([=== Код файла #raw("myArray.cpp")])
#let methods = read("../../src/work_3/vector/source/my_vector.cpp")
#raw(methods, lang: "cpp")


#text([=== Код файла #raw("main.cpp")])

#text([
  _Комментарий: в данном файле показан пример работы программы для теста №1_ \
])

#let methods = read("../../src/work_3/vector/main.cpp")
#raw(methods, lang: "cpp")

#align(
  center,
  text([== Скриншоты результатов тестирования])
)

#align(
  left, [
    #text([
      Тест 1. 
    ])

    #image("images/test_2_1.png", width: 80%)
    
    #text([
      Тест 2. 
    ])

    #image("images/test_2_2.png", width: 80%)
  ]
)