/*
 * Принцип lsp является основой для построения кода, который можно поддерживать и повторно использовать.
 * В нем говорится, что хорошо разработанный код может быть расширен без изменений;
 * что в хорошо разработанной программе новые функции добавляются путем добавления нового кода,
 * а не путем изменения старого, уже работающего кода.
 *
 * Тип S будет подтипом Т тогда и только тогда,
 * когда каждому объекту oS типа S соответствует некий объект oT типа T таким образом,
 * что для всех программ P, реализованных в терминах T,
 * поведение P не будет меняться, если oT заменить на oS.
 */

// 1.
void DrawShape(const Shape& s) {
    if (typeid(s) == typeid(Square))
        DrawSquare(static_cast<Square&>(s));
    else if (typeid(s) == typeid(Circle))
        DrawCircle(static_cast<Circle&>(s))
}

/*
 * Нарушение принципа:
 * Функция DrawShape должна знать о всех возможных производных от класса Shape,
 * и она должна быть изменена каждый раз, когда создаются новые производные классы.
 */

// 2.
class Rectangle {
    public:
        void SetWidth(double w) {itsWidth=w;}
        void SetHeight(double h) {itsHeight=w;}
        double GetHeight() const {return itsHeight;}
        double GetWidth() const {return itsWidth;}
    private:
        double itsWidth;
        double itsHeight;
};

/*
 * Квадрат является прямоугольником.
 * Квадрату не нужны переменные-члены itsHeight и itsWidth и функции SetWidth и SetHeight (длина и ширина одна у квадрата).
 * Но он все равно унаследует их.
 */

void Square::SetWidth(double w) {
    Rectangle::SetWidth(w);
    Rectangle::SetHeight(w);
}
void Square::SetHeight(double h) {
    Rectangle::SetHeight(h);
    Rectangle::SetWidth(h);
}

// Таким образом, инварианты квадрата остаются нетронутыми.

// 3.
void f(Rectangle& r) {
    r.SetWidth(32);
}

/*
 * Если мы передадим ссылку на квадратный объект в эту функцию, квадратный объект будет поврежден,
 * потому что высота не будет изменена. Это явное нарушение LSP. Функция f не работает для производных своих доводов.
 * Причиной сбоя является то, что SetWidth и SetHeight не были объявлены виртуальными в прямоугольнике.
 * Мы можем сделать их виртуальными, но установка высоты и ширины прямоугольника это простые операции,
 * такие же проблемв будут появляться и далее.
 * Когда создание производного класса заставляет нас вносить изменения в базовый класс, это часто подразумевает, что дизайн неисправен.
 */

class Rectangle {
    public:
        virtual void SetWidth(double w) {itsWidth=w;}
        virtual void SetHeight(double h) {itsHeight=h;}
        double GetHeight() const {return itsHeight;}
        double GetWidth() const {return itsWidth;}
    private:
        double itsHeight;
        double itsWidth;
};

class Square : public Rectangle {
    public:
        virtual void SetWidth(double w);
        virtual void SetHeight(double h);
};
void Square::SetWidth(double w) {
    Rectangle::SetWidth(w);
    Rectangle::SetHeight(w);
}
void Square::SetHeight(double h) {
    Rectangle::SetHeight(h);
    Rectangle::SetWidth(h);
}

// Казалось бы все хорошо, однако рассмотрим функцию g

// 4.
void g(Rectangle& r) {
    r.SetWidth(5);
    r.SetHeight(4);
    assert(r.GetWidth() * r.GetHeight()) == 20);
}

/* Функция отлично работает для прямоугольника, но при передаче квадрата объявляет ошибку утверждения.
 * Эта функция обнаруживает нарушение LSP.
 *
 * Используем пред- и постусловия.
 *
 * Постусловие для Rectangle::SetWidth(double w):
 */

assert((itsWidth == w) && (itsHeight == old.itsHeight));