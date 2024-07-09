#let head1(theme) = {
  set align(center)
  text(size: 16pt, [#theme])
}

#let head2(theme) = {
  set align(center)
  text(size: 14pt, [#theme])
}

#let un_heading(theme) = {
  align(center, text(size: 16pt,[*#theme*
    ])
  )
}

#let indent = h(1.25cm)

#let tab = h(0.5cm)

// Костыль. Пока что не нашел, как выровнять caption по левой стороне
#let tab_caption(num, capt) = {
  align(
    left, [Таблица #num -- #capt]
  )
}

// Темплейты оформления списка литературы

#let bibliography(
  author,
  title, 
  responsibility, 
  edit_place, 
  pub_house, 
  edit_year, 
  pages, 
  ISBN
) = {
  text([#author. #title / #responsibility. -- #edit_place: #pub_house, #edit_year. -- #pages. -- #ISBN])
}

#let internet(
  title,
  website,
  URL,
  address_date
) = {
  text([#title \/\/ #website URL: #URL (дата обращения: #address_date)])
}