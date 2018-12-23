/*
 * Большинство решений, которые я просмотрела (google), говорят о создании базового класса (Polygon),
 * от которого и Прямоугольник, и Квадрат наследуются. Но при таком решении квадрат перестает быть прямоугольником.
 *
 * Другое решение, которое я нашла - существует только тип прямоугольника и у него метод isSquare,
 * который проверяет равна ли длина и высота у прямоугольника.
 * Но в задании сказано о реализации двух классов.
 *
 * Идея, которая понравилась мне больше всего, это идея ответить себе на два вопроса:
 * 1. Крадрат и Прямоугольник - изменяемые типы?
 * 2. Является ли каждый Прямоугольник с одинаковой шириной и высотой Квадратом?
 * В зависимости от ответа на эти вопросы меняется ответ на вопрос
 * 'Реально ли это реализовать и насколько просто?'
 */

/*
 * 1. Изменяемы? Да
 * 2. Равносторонний Прямоугольник - Квадрат? Да
 * Это невозможно и это демонстрируется в 'lsp-breaking.cpp'
*/

/*
 * 1. Изменяемы? Нет
 * 2. Равносторонний Прямоугольник - Квадрат? Да
 * Тогда при создании Прямоугольника придется прописывать условие вида
 * if (width == height) return new Square(width);
 * А Прямоугольник не должен знать о существовании Квадрата
*/

/*
 * 1. Изменяемы? Нет
 * 2. Равносторонний Прямоугольник - Квадрат? Нет
 */

public class Rectangle {
    public Rectangle(int width, int height) {
            Width = width;
            Height = height;
        }

    public int Width { get; private set; }
    public int Height { get; private set; }

    public double getPerimeter() {
            return 2*Width + 2*Height;
        }

    public double getArea() {
            return Width*Height;
        }
}
public class Square: Rectangle {
    public Square(int size): base(size, size) {}
}

Rectangle rectangle = new Rectangle(100, 100);
std::cout << rectangle is Square; // false

/*
 * 1. Изменяемы? Да
 * 2. Равносторонний Прямоугольник - Квадрат? Нет
 */

public class Rectangle {
    public int Width { get; protected set; }
    public int Height { get; protected set; }

    public virtual bool TrySetWidthAndHeight(int width, int height) {
            Width = width;
            Height = height;
            return true;
        }

    public double getPerimeter() {
            return 2*Width + 2*Height;
        }

    public double getArea() {
            return Width*Height;
        }
}
public class Square: Rectangle {
    public override bool TrySetWidthAndHeight(int width, int height) {
            if (width != height)
                return false;

            Width = width;
            Height = height;
            return true;
        }
}

// Название метода TrySetWidthAndHeight позволяет понять, что изменение значения может завершиться неудачей.