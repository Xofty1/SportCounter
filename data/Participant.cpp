#include <iostream>
#include <string>
#include <vector>
#include <QString>

using namespace std;

class Participant {
private:
    QString name;
    int number_of_team; // отряд
    int year;
    vector<double> scores; // результаты соревнований
    int total_points;
    int place;
    vector<int> points; // новое поле

public:
    Participant(const QString& name, int number_of_team, int year, vector<double> scores)
        : name(name), number_of_team(number_of_team), year(year), scores(scores), total_points(0), place(0), points() {}

    // Геттеры и сеттеры
    QString getName() const { return name; }
    int getNumberOfTeam() const { return number_of_team; }
    int getYear() const { return year; }
    int getTotalPoints() const { return total_points; }
    int getPlace() const { return place; }

    void setName(const QString& name) { this->name = name; }
    void setNumberOfTeam(int number_of_team) { this->number_of_team = number_of_team; }
    void setPlace(int place) { this->place = place; }
    void setYear(int year) { this->year = year; }
    void setTotalPoints(int total_points) { this->total_points = total_points; }

    // Получение всех результатов
    const vector<double>& getScores() const {
        return scores;
    }

    // Получение всех баллов
    const vector<int>& getPoints() const {
        return points;
    }

    void addPoints(int point) {
            points.push_back(point);
        }

    // Печать информации об участнике
    void printParticipantInfo() const {
        std::cout << "Name: " << name.toStdString() << ", Team: " << number_of_team
                  << ", Total Points: " << total_points << ", Place: " << place << std::endl;
    }
};
