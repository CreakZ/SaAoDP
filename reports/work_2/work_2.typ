#import "../title_page_template.typ": title_page
#import "../layouts.typ": head1, head2, tab, un_heading, indent, tab_caption

#set text(font: "New Computer Modern", size: 14pt)
#set heading(numbering: "1.")
#set page(paper: "a4", margin: 2cm)
#set figure.caption(separator: [ -- ])

#title_page(2, [Абстрактный тип данных и его реализация на одномерном статическом массиве])

#un_heading([Оглавление])

#outline(
  title: none,
  indent: none
)

#pagebreak()

#set par(justify: true, first-line-indent: 1.25cm)
#set page(numbering: "1")

#head1([= Условие задачи и задание варианта])

#head2([== Условие задачи])

#par(
  [#indent Дано множество из n целых чисел. Дан набор задач (операций), которые требуется выполнить над исходным множеством. Набор задач определен в варианте задания табл. 6.]
)

#par(
  [Разработать и реализовать АТД задачи, по управлению множеством посредством операций, указанных в варианте задания. В АТД включить операции по заполнению исходного множества и отображения множества.]
)

#par(
  [При разработке алгоритмов операций варианта могут быть выявлены
  дополнительные алгоритмы, например такие: определить является ли число простым, или определить сумму цифр числа, эти алгоритмы надо включить в раздел операций АТД.]
)

#head2([== Задание варианта])

#par(
  [#enum(
    tight: true,
    [Найти позицию элемента массива значение которого делится на каждую из цифр числа.],
    [Вставить в массив новый элемент после элемента, значение которого делится на каждую цифру значения.],
    [Удалить из массива все элементы, кратные трем.]
  )]
)

#pagebreak()

#head1([= АТД задачи])

#let tab(theme) = {
  set par(first-line-indent: 1.25cm, hanging-indent: 1.25cm)
  text([#theme #linebreak()])
}

#let method(num, head, pre, post, header) = {
  set par(hanging-indent: 1.25cm, first-line-indent: 1.25cm)
  par([
    #num #head #linebreak()
  ])
  par([
    Предусловие: #pre #linebreak()
  ])
  par(
    [Постусловие: #post #linebreak()]
  )
  par(
    [Заголовок: #header #linebreak()]
  )
}

#par(
  justify: true,
  [
    АТД myArray \
    { \ 
    #tab([_Данные_ (описание свойств структуры данных задачи)])
    #tab([N – максимальное количество элементов в множестве])
    #tab([n – длина массива])
    #tab([arr – список значений элементов массива])

    #tab([_Операции_ (объявления операций)])

      #method(
        [1.], 
        [Метод, осуществляющий вывод текущих значений множества], 
        [нет],
        [выведенные через пробел элементы массива],
        [#raw("printElements()")]
      )

      #method(
      [2.],
      [Метод, осуществляющий заполнение массива случайными значениями],
      [нет],
      [массив, заполненный случайными значениями],
      [#raw("fillRandomly()")]
      )

      #method(
        [3.],
        [Метод, осуществляющий заполнение массива вручную – с клавиатуры],
        [нет], 
        [массив, заполненный значениями, введенными с клавиатуры],
        [#raw("fillManually()")]
      )

      #method(
        [4.],
        [Метод, возвращающий индекс первого элемента, делящегося на каждую из своих цифр. В случае отсутствия такового элемента возвращается -1],
        [нет],
        [число – индекс первого элемента, нацело делящегося на каждую из своих цифр],
        [#raw("getIndex()")]
      )

      #method(
        [5.],
        [Метод осуществляющий вставку элемента newElem на позицию с индексом pos],
        [pos – индекс элемента, на место которого требуется вставить новый элемент, newElem – значение нового элемента],
        [массив arr длиной n+1 со вставленным элементом newElem на позиции pos],
        [#raw("insert(int pos, int newElem)")]
      )

      #method(
        [6.],
        [Метод, осуществляющий вставку нового элемента newElem после элемента с индексом getIndex(). Если getIndex() = -1, вставка производится в начало массива],
        [newElem – значение нового элемента],
        [массив arr длиной $n+1$ со вставленным элементом newElem на позиции getIndex()+1],
        [#raw("getIndexInsert(int newElem)")]
      )

      #method(
        [7.],
        [Метод, осуществляющий удаление из массива всех элементов, нацело делящихся на 3],
        [нет],
        [измененный массив arr, содержащий элементы, не делящихся нацело на 3],
        [#raw("deleteMultiplesOfThree()")]
      )
      \
    }

    
  ]
)

#pagebreak()

#head1([= Разработка программы])

#head2([== Реализация данных АТД])

#let code = read("../../src/work_2/headers/myArray.h")
#raw(code, lang: "cpp")

#pagebreak()

#head2([== Алгоритмы методов])

#tab_caption(1, [Псевдокод для метода, реализующего удаление элемента в заданной позиции])

#let tab = 0.5cm

#figure(
  kind: table,
  
  table(
    columns: 2,
    align: (center, left),

    table.header(
      table.cell(
        colspan: 2,
        [#raw("void erase(int pos)", lang: "cpp")]
      )
    ),

    [Номер], table.cell(
        align: center, [Инструкция]
    ),

    

    [1], [if $not$(pos > -1 $and$ pos < n) then],
    [2], [#h(0.5cm) Вывод $quote.double.l.angle$ Невозможно удалить элемент: неверный индекс!$quote.double.r.angle$], 
    [3], [endIf],
    [4], [for i $<-$ to n $-$ 2 do],
    [5], [#h(0.5cm) arr[$i$] $<-$ arr[$i+1$]],
    [6], [od],
    [7], [n $<-$ n + 1]
  )
)

#tab_caption(2, [Псевдокод для метода, реализующего вставку элемента в заданной позиции])

#figure(
  kind: table,
  
  table(
    columns: 2,
    align: (center, left),

    table.header(
      table.cell(
        colspan: 2,
        [#raw("void insert(int pos, int newElem)", lang: "cpp")]
      )
    ),

    [Номер], table.cell(
        align: center, [Инструкция]
    ),

    [1], [if $not$(pos > -1 $and$ pos < n) then],
    [2], [#h(0.5cm) Вывод $quote.double.l.angle$Невозможно вставить элемент: неверный индекс!$quote.double.r.angle$],
    [3], [endIf],
    [4], [prev $<-$ arr[pos]],
    [5], [arr[pos] $<-$ newElem],
    [6], [for i $<-$ pos + 1 to n + 1 do],
    [7], [#h(0.5cm) temp $<-$ arr[i]],
    [8], [#h(0.5cm) arr[i] $<-$ prev],
    [9], [#h(0.5cm) prev $<-$ temp],
    [10], [od],
    [11], [n $<-$ n + 1]
  )
)

#pagebreak()

#tab_caption(3, [Псевдокод для метода, реализующего поиск первого элемента, делящегося нацело на каждую из своих цифр])

#figure(
  kind: table,
  
  table(
    columns: 2,
    align: (center, left),


    table.header(
      table.cell(
        colspan: 2,
        [#raw("void getIndex()", lang: "cpp")]
      )
    ),

    [Номер], table.cell(
        align: center, [Инструкция]
    ),

    [1], [for i $<-$ to n $-$ 1 do],
    [2], [#h(0.5cm) number $<-$ arr[$i$]],
    [3], [#h(0.5cm) while number > 0 do],
    [4], [#(2*h(0.5cm)) if number $mod$ 10 $eq.not$ 0 then],
    [5], [#(3*h(0.5cm)) if arr[$i$] $mod$ (number $mod$ 10) $eq.not$ 0 then],
    [6], [#(4*h(0.5cm)) break],
    [7], [#(3*h(0.5cm))endIf],
    [8], [#(2*h(0.5cm)) else],
    [9], [#(3*h(0.5cm)) break],
    [10], [#(2*h(0.5cm))endIf],
    [11], [#(2*h(0.5cm))number $<-$ number $"div"$ 10],
    [12], [#h(0.5cm) od],
    [13], [#h(0.5cm) if number $=$ 0 then],
    [14], [#(2*h(0.5cm)) return i],
    [15], [#h(0.5cm) endIf],
    [16], [return -1]
  )
)

#pagebreak()

#head2([== Таблица тестов операций])

#figure(
  kind: table,

  table(
    columns: 4,
    align: (center, center, left, left),

    table.header(
      [Номер], [Операция], 
      table.cell(
        align: center,
        [Входные данные]
      ),
      table.cell(
        align: center,
        [Результат работы]
      )
    ),

    [1], [#raw("erase")], [n=7 \ arr={1, 2, 3, 5, 8, 13, 21} \ pos=3], [n=6 \ arr={1, 2, 3, 8, 13, 21}],
    [2], [#raw("erase")], [n=2 \ arr={9, 11} \ pos=2], [Ошибка: $quote.double.l.angle$Невозможно удалить элемент: неверный индекс!$quote.double.r.angle$],
    [3], [#raw("insert")], [n=7 \ arr={1, 2, 3, 5, 8, 13, 21} \ pos=3 \ newElem=4], [n=8 \ arr={1, 2, 3, 4, 5, 8, 13, 21}],
    [4], [#raw("insert")], [n=5 \ arr={2, 2, 2, 2, 2} \ pos=5 \ newElem=8], [Ошибка: $quote.double.l.angle$Невозможно вставить в массив: неверный индекс!$quote.double.r.angle$],
    [5], [#raw("getIndex")], [n=7 \ arr={13, 17, 31, 53, 15, 13, 21}], [4],
    [6], [#raw("getIndex")], [n=3 \ arr={13, 17, 97}], [-1]
  )
)

#pagebreak()

#head2([== Код проекта])

#head2([=== Файл #raw("myArray.cpp")])

#let arr_code = read("../../src/work_2/source/myArray.cpp")
#raw(arr_code, lang: "cpp")

#pagebreak()

#head2([=== Файл #raw("main.cpp")])

#let main_code = read("../../src/work_2/main.cpp")
#raw(main_code, lang: "cpp")

#pagebreak()

#head1([= Скриншоты результатов тестирования])

#par(
  [#indent _Комментарий: на скриншотах ниже первое число – это длина массива n, а следующие n чисел – введенные вручную элементы массива. Далее в зависимости от введенных данных и вызываемого метода выводится результат работы (элементы массива через пробел, текст ошибки или число)._]
)

#figure(
  image(
    width: 60%,
    "images/test1.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №1]
)

#figure(
  image(
    width: 60%,
    "images/test2.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №2]
)

#figure(
  image(
    width: 60%,
    "images/test3.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №3]
)

#figure(
  image(
    width: 60%,
    "images/test4.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №4]
)

#figure(
  image(
    width: 60%,
    "images/test5.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №5]
)

#figure(
  image(
    width: 60%,
    "images/test6.png"
  ),
  supplement: [Рисунок],
  caption: [Тест №6]
)