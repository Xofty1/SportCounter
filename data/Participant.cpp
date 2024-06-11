#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include <QTime>

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
    QTime start;
    QTime end;
    QTime total_time;
    int penalty_loop = 0;

public:
    Participant(const QString& name, int number_of_team, int year, vector<double> scores)
        : name(name), number_of_team(number_of_team), year(year), scores(scores), total_points(0), place(0), points() {}

    Participant(const QString& name, int number_of_team, int year, QTime start,QTime end, QTime total_time,int penalty_loop )
        : name(name), number_of_team(number_of_team), year(year), start(start), end(end), total_time(total_time),penalty_loop(penalty_loop) {}

    // Геттеры и сеттеры
    QString getName() const { return name; }
    QTime getStart() const { return start; }
    QTime getEnd() const { return end; }
    QTime getTotalTime() const { return total_time; }
    int getNumberOfTeam() const { return number_of_team; }
    int getYear() const { return year; }
    int getTotalPoints() const { return total_points; }
    int getPlace() const { return place; }
    int getPenaltyLoop() const { return penalty_loop; }

    void setName(const QString& name) { this->name = name; }
    void setNumberOfTeam(int number_of_team) { this->number_of_team = number_of_team; }
    void setPlace(int place) { this->place = place; }
    void setYear(int year) { this->year = year; }
    void setPenaltyLoop(int penalty_loop) { this->penalty_loop = penalty_loop; }
    void setTotalPoints(int total_points) { this->total_points = total_points; }
    void setStart(QTime start) { this->start = start; }
    void setEnd(QTime end) { this->end = end; }
    void setTotalTime(QTime total_time) { this->total_time = total_time; }

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
