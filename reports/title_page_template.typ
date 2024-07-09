#let title_page(work_num, theme) = {
  set par(justify: false)
  
  align(
    center, [

    #image("mirea.png")

    #text(size: 10pt, [
      МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ
    ])

    #text([
      Федеральное государственное бюджетное образовательное учреждение высшего образования
    ])

    #text([
      *"МИРЭА - Российский технологический университет"*
    ])

    #text(size: 18pt, [
      *РТУ МИРЭА*
    ])

    #stack(
      spacing: 0.15em,
      line(length: 100%, stroke: 0.5pt),
      line(length: 100%, stroke: 0.5pt),
    )

    #stack(
      dir: ttb,
      spacing: .6em,
      text([Институт информационных технологий (ИТ)]),
      text([Кафедра математического обеспечения и стандартизации информационных технологий (МОСИТ)])
    )

    #block(
      above: 3em,
      below: 5em,
      [
        #stack(
          dir: ttb,
          spacing: .6em,
          text(
            size: 14pt, [
            *ОТЧЕТ ПО ПРАКТИЧЕСКОЙ РАБОТЕ №#work_num*
            ]
          ),

          text(
            size: 14pt, [
            *по дисциплине*
            ]
          ),

          text(
            size: 14pt, [
            *«Структуры и алгоритмы обработки данных»*
            ]
          )
        )

        #text(
          size: 14pt, [
            Тема «#theme»
          ]
        )
      ]
    )

    #grid([
      #text(
        size: 12pt, [
        #v(1fr) #h(30%) Выполнил студент группы ИКБО-50-23 #h(1fr) Русаков М.Ю.
      ])
    
      #text(
        size: 12pt, [
        #h(30%) Принял старший преподаватель #h(1fr) Скворцова Л.А. #v(4fr) 
      ])

      #text([
        Москва #datetime.today().year()
      ])
    ])
    
    #pagebreak()
  ])
}