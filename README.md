Метод CreateArrayAtMemory викликається два рази. Коли метод викликається вперше, відбувається розрахунок кількості байтів, необхідних для побудови n-вимірного масиву. Потім ця кількість байтів призначається вектору, створюючи блок пам'яті. Метод data контейнера вектора повертає вказівник на початок цього блоку пам'яті. При наступному виклику методу CreateArrayAtMemory ми виділяємо необхідну пам'ять для вказівників на масиви та для значень, які ми хочемо зберегти.

В даній програмі використовується такий інструмент, як "варіативний шаблон". Він дозволяє передавати будь-яку кількість розмірностей масиву як параметри функції. Перший параметр є вказівником на виділену пам'ять в якій ми будемо розміщати всі наші дані. Тут використаний тип void*, який дозволяє передавати вказівник на любий тип даних.

При виклику методу CreateArrayAtMemory вперше, важливо правильно вказати тип елементів у кутових дужках для коректного розрахунку кількості байтів та передати nullptr у параметрах методу разом з розмірностями масиву. Потім ми обчислюємо PS (розмір нашого вказівника) і множимо його на першу розмірність масиву. Після цього ми проходимо через цикл, щоб визначити розмір пам'яті, необхідний для зберігання нашої матриці. При наступному виклику методу CreateArrayAtMemory функція спершу рахує скільки потрібно пам'яті для вказівників. Після цього рахує вказівники на області даних і вписує їх послідовно в пам'ять.

Розв'язання проблеми виклику методу CreateArrayAtMemory може здатися важливим. Можливо, варто переглянути його реалізацію, щоб можна було викликати лише один раз. Як на мене, те що функція викликається двічі, є абсолютно нормальним, наприклад функції в windows API часто так роблять.

Щодо використання іншого контейнера замість вектора, такого як дека, варто зазначити, що у деки немає методу data. Проте можна просто виділити пам'ять за допомогою new (як я поступив в свому коді).