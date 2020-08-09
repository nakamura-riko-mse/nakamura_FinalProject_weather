#include <iostream>
#include<vector>
#include<fstream>
#include<regex>
#include<string>

using namespace std;

class weather {
protected:
    string day;
    double temp = 0;
    double tempMax = 0;
    double rain = 0;
    double sun = 0;
    double wind = 0;
    double hum = 0;
    string weatherAM;
    string weatherPM;


public:
    void setDay(const string& newDay) { day = newDay; }
    string getDay() { return day; }
    void setTemp(double newTemp) { temp = newTemp; }
    double getTemp() { return temp; } 
    void setTempMax(double newTempMax) { tempMax = newTempMax; }
    double getTempMax() { return tempMax; }
    void setRain(double newRain) { rain = newRain; }
    double getRain() { return rain; }
    void setSun(double newSun) { sun = newSun; }
    double getSun() { return sun; }
    void setWind(double newWind) { wind = newWind; }
    double getWind() { return wind; }
    void setHum(double newHum) { hum = newHum; }
    double getHum() { return hum; }
    void setWeatherAM(const string& newWeatherAM) { weatherAM = newWeatherAM; }
    string getWeatherAM() { return weatherAM; }
    void setWeatherPM(const string& newWeatherPM) { weatherPM = newWeatherPM; }
    string getWeatherPM() { return weatherPM; }
};




void readFromFile(string fileName)
{
    vector<weather>v1;
    ifstream infile(fileName);

    int n = 0;

    string DAY;
    double TEMP;
    double TEMPMAX;
    double RAIN;
    double SUN;
    double WIND;
    double HUM;
    string WEATHERAM;
    string WEATHERPM;

    while (infile >> DAY >> TEMP >>TEMPMAX>> RAIN >>SUN>>WIND>> HUM >> WEATHERAM>>WEATHERPM) {

        v1.emplace_back();

        v1[n].setDay(DAY);
        v1[n].setTemp(TEMP);
        v1[n].setTempMax(TEMPMAX);
        v1[n].setRain(RAIN);
        v1[n].setSun(SUN);
        v1[n].setWind(WIND);
        v1[n].setHum(HUM);
        v1[n].setWeatherAM(WEATHERAM);
        v1[n].setWeatherPM(WEATHERPM);
        n++;
    }

    size_t s = v1.size();
    for (size_t i = 0;i < s;++i) {//要素の最後まで繰り返す

        //気温の表示
        cout << v1[i].getDay() << "　この日の"<<fileName<<"の平均気温は" << v1[i].getTemp() 
            << "℃　最高気温は"<<v1[i].getTempMax()<<"℃です。"<< endl;

        //夏の注意喚起、最高気温について
        if(v1[i].getTempMax()>29)
        {
            cout << "真夏日となります、熱中症には十分気をつけましょう" << endl;
        }
        else if(v1[i].getTempMax()>24)
        {
            cout << "夏日です。野外での活動の際は水分をしっかり補給しましょう" << endl;
        }


      //前日との気温の比較
        if (i==0) { cout << ""; }
         else if(v1[i].getTemp() > v1[i-1].getTemp())
        { cout << "前日より暑いでしょう" <<endl;}
         else if (v1[i].getTemp() > v1[i - 1].getTemp()) 
        {  cout << "前日より涼しいです" << endl; }

        //気象情報の表示
        cout << "また降水量は" << v1[i].getRain()
            << "mm、\n 日照時間は" << v1[i].getSun() << "時間で、平均風速は" << v1[i].getWind()
            << "m/sです。湿度" << v1[i].getHum() << "％　\n 午前中の天気は“" << v1[i].getWeatherAM()
            << "”午後の天気は“" << v1[i].getWeatherPM() << "”です。" << endl;

        //湿度について
        if (v1[i].getHum()>80) {
            cout << "蒸し蒸しとした一日になるでしょう" << endl;
        }


     //洗濯物
        if (v1[i].getRain() != 0) { }
        else if(v1[i].getSun()<10){
            cout<<"洗濯日和です。"<<endl;
            if (v1[i].getWind()>4) {
                cout << "しかし，風で飛ばされないよう気をつけましょう" << endl;
            }
        }

        cout  << endl;
        
        
    }
}

int main() {

    readFromFile("東京.txt");

}


