// CONCERN BASE CLASS
class Concern
{
public:
    // Constructor & Destructor
    Concern(string name) : m_name(name) {}
    virtual ~Concern() {}
    
    // Member functions
    virtual string description() const = 0;
    virtual bool possibleFelony() const;
    string person() const;
    
private:
    string m_name;
};

bool Concern::possibleFelony() const
{
    return false;
}

string Concern::person() const
{
    return m_name;
}


// ETHICSMATTER DERIVED CLASS
class EthicsMatter : public Concern
{
public:
    // Constructor & Destructor
    EthicsMatter(string name) : Concern(name) {}
    virtual ~EthicsMatter();
    
    // Member functions
    virtual string description() const;
};

EthicsMatter::~EthicsMatter()
{
    cout << "Destroying " << this->person()
         << "'s ethics matter" << endl;
}

string EthicsMatter::description() const
{
    return "An ethics matter";
}


// HUSHPAYMENT DERIVED CLASS
class HushPayment : public Concern
{
public:
    // Constructor & Destructor
    HushPayment(string name, int money) : Concern(name), m_money(money) {}
    virtual ~HushPayment();
    
    // Member functions
    virtual string description() const;
private:
    int m_money;
};

HushPayment::~HushPayment()
{
    cout << "Destroying " << this->person()
    << "'s hush payment" << endl;
}

string HushPayment::description() const
{
    return "A $" + to_string(m_money) + " payment";
}


// INVESTIGATION DERIVED CLASS
class Investigation : public Concern
{
public:
    // Constructor & Destructor
    Investigation(string name) : Concern(name) {}
    virtual ~Investigation();
    
    // Member functions
    virtual string description() const;
    virtual bool possibleFelony() const;
};

Investigation::~Investigation()
{
    cout << "Destroying " << this->person()
    << "'s investigation" << endl;
}

string Investigation::description() const
{
    return "An investigation";
}

bool Investigation::possibleFelony() const
{
    return true;
}

