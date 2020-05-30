#include <iostream>
using namespace std;
/////抽象层
class CPU
{
public:
    virtual void calculte() = 0;
};
class Card
{
public:
    virtual void display() = 0;
};
class Mem
{
public:
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, Card *card, Mem *mem)
    {
        this->cpu = cpu;
        this->card = card;
        this->mem = mem;
    }
    void work()
    {
        this->cpu->calculte();
        this->card->display();
        this->mem->storage();
    }
    ~Computer()
    {
        if (this->cpu != NULL)
        {
            delete this->cpu;
            this->cpu;
        }
        if (this->card != NULL)
        {
            delete this->card;
            this->card;
        }
        if (this->mem != NULL)
        {
            delete this->mem;
            this->mem;
        }
    }

private:
    CPU *cpu;
    Card *card;
    Mem *mem;
};
/////实现层
class InterCPU : public CPU
{
    virtual void calculte()
    {
        cout << "使用inter cpu calculate()" << endl;
    }
};
class InterCard : public Card
{
    virtual void display()
    {
        cout << "使用inter 显卡 display()" << endl;
    }
};
class InterMem : public Mem
{
    virtual void storage()
    {
        cout << "使用inter 内存 storage()" << endl;
    }
};

int main(int argc, char **arg)
{
    InterCPU *cpu = new InterCPU();
    InterCard *card = new InterCard();
    InterMem *mem = new InterMem();
    Computer *com1 = new Computer(cpu, card, mem);
    com1->work();
    delete com1;
    // delete cpu;
    return 0;
}