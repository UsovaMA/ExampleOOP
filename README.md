# ExampleOOP

Шаблон для изучения основ ООП (объектно-ориентированного программирования). 

Цели:
- изучить основные понятия в ООП;
- поработать над стилем кодирования в ваших программах;
- повторить базовые действия при работе с системой git.


План по выполнению задания:
1. добавить оружие персонажам,
2. избавиться от ужасного создания персонажей путём заполнения полей (конструкторы),
3. проблема: я могу изменить силу, здоровье и прочие показатели как хочу - читы! необходимо сокрытие информации (переход от структуры к классам, сеттеры/геттеры),
4. перенести метод печати, работающий с полями (а они закрыты теперь!), внутрь класса,
5. дублирование кода! решение: полиморфизм + наследование (выделение класса Персонаж + модификатор доступа protected + список инициализации в конструкторе),
6. создание методов, которые работают одинаково со всеми унаследованными классами (восстановление здоровья и проверка на критический урон),
7. создание методов, относящихся ко всем видам персонажей (виртуальные методы) - сначала print, затем атаки.

Самостоятельно: доделать классы-потомки у Персонажа, организовать сходную структуру у системы классов Оружие.

https://docs.google.com/spreadsheets/d/1mhWoqNYzbAO3Qelq1jaRQXjDq1HvilVeSgbpnKRbdB0/edit?usp=sharing
