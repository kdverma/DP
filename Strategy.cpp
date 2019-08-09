#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<memory>

using namespace std;
enum class OutputFormat{markdown,html};

struct Strategy
{
    public:
    virtual ~Strategy() = default;

    virtual void add_item(ostringstream &oss,const string &str) = 0;

    virtual void start(ostringstream &oss)
    {

    };

    virtual void end(ostringstream &oss)
    {

    };

    /* data */
};

struct MarkupStrategy : Strategy
{
    /* data */
    void add_item(ostringstream &oss, const string &str)
    {
        oss << " * " <<  str << "\n";
    }
};

struct HtmlStrategy : Strategy
{
    void start(ostringstream &oss)
    {
        oss << "<ul>" << "\n";
    }

    void add_item(ostringstream &oss,const string &item)
    {
        oss << "<li>" << item << "</li>" << "\n"; 
    }

    void end(ostringstream &oss)
    {
        oss << "</ul>" << "\n";
    }
};

struct TextProcessor
{
    private:
    ostringstream oss;
    unique_ptr<Strategy> strategy;

    public:
    void setOutputFormat(const OutputFormat &format)
    {
        switch (format)
        {
        case OutputFormat::markdown:
            strategy = make_unique<MarkupStrategy>();
            break;
        
        case OutputFormat::html:
            strategy = make_unique<HtmlStrategy>();
            break;
        default:
            throw runtime_error("unknown strategy");
            break;
        }
    }

    void append_list(const vector<string> &vec)
    {
        strategy->start(oss);
        for(auto &item : vec)
        {
            strategy->add_item(oss,item);
        }
        strategy->end(oss);
    }

    string str ()
    {
        return oss.str();
    }

    void clear()
    {
        oss.str("");
        oss.clear();
    }

};


int main()
{
    TextProcessor tp;
    tp.setOutputFormat(OutputFormat::markdown);
    tp.append_list({"kapil","dev","verma"});
    cout << tp.str();

    tp.clear();

    tp.setOutputFormat(OutputFormat::html);
    tp.append_list({"jai", "ho"});
    cout << tp.str();
    return 0;
}