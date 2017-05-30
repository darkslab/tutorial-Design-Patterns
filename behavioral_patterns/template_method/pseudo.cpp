class View {
public:
    void Display();

protected:
    View();

    virtual void SetFocus();
    virtual void ResetFocus();
    virtual void DoDisplay() = 0;
};

void View::Display()
{
    SetFocus();
    DoDisplay();
    ResetFocus();
}


class MyView: public View {
public:
    MyView();

protected:
    virtual void DoDisplay();
};

void MyView::DoDisplay()
{
    // render the view's contents
}
