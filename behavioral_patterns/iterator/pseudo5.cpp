template <class Item>
class ListTraverser {
public:
    ListTraverser(List<Item>* aList);
    bool Traverse();

protected:
    virtual bool ProcessItem(const Item&) = 0;

private:
    ListIterator<Item> _iterator;
};

template <class Item>
ListTraverser<Item>::ListTraverser(List<Item>* aList): _iterator(aList)
{
}

template <class Item>
bool ListTraverser<Item>::Traverse()
{
    bool result = false;

    for (_iterator.First(); !_iterator.IsDone(); _iterator.Next()) {
        result = ProcessItem(_iterator.CurrentItem());

        if (result == false) {
            break;
        }
    }

    return result;
}

class PrintNEmployees: public ListTraverser<Employee*> {
public:
    PrintNEmployees(List<Employee*>* aList, int n): ListTraverser<Employee*>(aList), _total(n), _count(0)
    {
    }

protected:
    bool ProcessItem(Employee* const&);

private:
    int _total;
    int _count;
};

bool PrintNEmployees::ProcessItem(Employee* const& e)
{
    _count++;
    e->Print();
    return _count < _total;
}


List<Employee*>* employees;
// ...

PrintNEmployees pa(employees, 10);
pa.Traverse();

ListIterator<Employee*> i(employees);
int count = 0;

for (i.First(); !i.IsDone(); i.Next()) {
    count++;
    i.CurrentItem()->Print();

    if (count >= 10) {
        break;
    }
}


template <class Item>
class FilteringListTraverser {
public:
    FilteringListTraverser(List<Item>* aList);
    bool Traverse();

protected:
    virtual bool ProcessItem(const Item&) = 0;
    virtual bool TestItem(const Item&) = 0;

private:
    ListIterator<Item> _iterator;
};

template <class Item>
bool FilteringListTraverser<Item>::Traverse()
{
    bool result = false;

    for (_iterator.First(); !_iterator.IsDone(); _iterator.Next()) {
        if (!TestItem(_iterator.CurrentItem())) {
            continue;
        }

        result = ProcessItem(_iterator.CurrentItem());

        if (result == false) {
            break;
        }
    }

    return result;
}
