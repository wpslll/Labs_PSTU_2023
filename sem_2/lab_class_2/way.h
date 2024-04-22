#include <string>
using namespace std;
class trip
{
private:
	string start;
	string end;
	float time;
public:
	trip();
	trip(string, string, float);
	~trip();
	trip(const trip&);
	string get_start();
	string get_end();
	float get_time();
	void set_start(string s);
	void set_end(string e);
	void set_time(float t);
	void show();
};