#include <iostream>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "AdjacencyList.h"
#include <set>
using namespace std;

// Prints the first line in the statistics window
void printHeader(sf::RenderWindow &window, sf::Font font, string stringText) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(45);
    text.setString(stringText);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(891, 515);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Underlined);

    window.draw(text);
}

// Print the second line in the statistics window
void printSecondLine(sf::RenderWindow &window, sf::Font font, string stringText) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(35);
    text.setString(stringText);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(891, 570);
    text.setFillColor(sf::Color::Black);

    window.draw(text);
}

// Prints third line in statistics window (if necessary)
void printThirdLine(sf::RenderWindow &window, sf::Font font, string stringText) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString(stringText);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(891, 605);
    text.setFillColor(sf::Color::Black);

    window.draw(text);
}

// Prints 1st Search Line (For Current Selected Statistic)
void printSearchLine(sf::RenderWindow &window, sf::Font font, string stringText) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(35);
    text.setString(stringText);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(891, 215);
    text.setFillColor(sf::Color::Black);

    window.draw(text);
}

// Prints 2nd Search Line (For Current Selected Statistic)
void printSearchLine2(sf::RenderWindow &window, sf::Font font, string stringText) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(35);
    text.setString(stringText);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(891, 290);
    text.setFillColor(sf::Color::Black);

    window.draw(text);
}

int main()
{

    AdjacencyList studentList;
    string firstName;
    string lastName;
    string university;
    string salary;
    string gradSchool;
    string id;
    string numInternships;
    string employed;
    string major;
    string buffer;

    set<string> colleges;
    set<string> majors;
    set<int> ids;

    fstream input("UniStudentData.csv");

    getline(input, buffer);

    while (!input.eof()) {
        getline(input, firstName, ',');
        getline(input, lastName, ',');
        getline(input, university, ',');
        getline(input, salary, ',');
        getline(input, gradSchool, ',');
        getline(input, id, ',');
        getline(input, numInternships, ',');
        getline(input, employed, ',');
        getline(input, major);

        colleges.insert(university);
        majors.insert(major);
        ids.insert(stoi(id));

        studentList.insert(firstName, lastName, university, salary, gradSchool, id, numInternships, employed, major);

    }

    string option;
    int intOption;
    bool systemEnd = false;
    string mode = "DFS";

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "University & Beyond by Christopher Tressler, Vy Vu, & Kushal Gaddam");

    // Background Image
    sf::Texture background;
    background.loadFromFile("images/Background.jpg");
    sf::Sprite backgroundSprite(background);

    // Logo Text Image
    sf::Texture logoText;
    logoText.loadFromFile("images/LogoText.png");
    sf::Sprite logoTextSprite(logoText);
    logoTextSprite.setOrigin(logoTextSprite.getLocalBounds().left + logoTextSprite.getLocalBounds().width / 2.0f, logoTextSprite.getLocalBounds().top + logoTextSprite.getLocalBounds().height / 2.0f);
    logoTextSprite.setPosition(281, 225);

    // Logo Globe Image
    sf::Texture logoSphere;
    logoSphere.loadFromFile("images/LogoSphere.png");
    sf::Sprite logoSphereSprite(logoSphere);
    logoSphereSprite.setOrigin(logoSphereSprite.getLocalBounds().left + logoSphereSprite.getLocalBounds().width / 2.0f, logoSphereSprite.getLocalBounds().top + logoSphereSprite.getLocalBounds().height / 2.0f);
    logoSphereSprite.setPosition(281, 225);

    // Salary Data Image
    sf::Texture salaryData;
    salaryData.loadFromFile("images/SalaryData.png");
    sf::Sprite salaryDataSprite(salaryData);
    salaryDataSprite.setPosition(618, 340);

    // Internship Data Image
    sf::Texture internshipData;
    internshipData.loadFromFile("images/InternshipData.png");
    sf::Sprite internshipDataSprite(internshipData);
    internshipDataSprite.setPosition(618, 190);

    // Graduate Data Image
    sf::Texture graduateData;
    graduateData.loadFromFile("images/GradData.png");
    sf::Sprite gradDataSprite(graduateData);
    gradDataSprite.setPosition(618, 265);

    // Exit Program
    sf::Texture exitProgram;
    exitProgram.loadFromFile("images/ExitProgram.png");
    sf::Sprite exitProgramSprite(exitProgram);
    exitProgramSprite.setPosition(914, 340);

    // Go Back
    sf::Texture goBack;
    goBack.loadFromFile("images/GoBack.png");
    sf::Sprite goBackSprite(goBack);
    goBackSprite.setPosition(1014, 340);

    // Go Home
    sf::Texture home;
    home.loadFromFile("images/Home.png");
    sf::Sprite homeSprite(home);
    homeSprite.setPosition(729, 340);

    // Next Button
    sf::Texture next;
    next.loadFromFile("images/next.png");
    sf::Sprite nextSprite(next);
    nextSprite.setPosition(1014, 265);

    // Previous Button
    sf::Texture previous;
    previous.loadFromFile("images/previous.png");
    sf::Sprite previousSprite(previous);
    previousSprite.setPosition(729, 265);

    // Description
    sf::Texture description;
    description.loadFromFile("images/Description.png");
    sf::Sprite descriptionSprite(description);
    descriptionSprite.setPosition(116, 450);

    // Stats Screen
    sf::Texture statsScreen;
    statsScreen.loadFromFile("images/StatScreen.png");
    sf::Sprite statsScreenSprite(statsScreen);
    statsScreenSprite.setPosition(618, 450);

    // BFS Mode
    sf::Texture BFS;
    BFS.loadFromFile("images/BFS.png");
    sf::Sprite BFSSprite(BFS);
    BFSSprite.setPosition(618, 115);

    // DFS Mode
    sf::Texture DFS;
    DFS.loadFromFile("images/DFS.png");
    sf::Sprite DFSSprite(DFS);
    DFSSprite.setPosition(618, 115);

    // Swap Search Modes
    sf::Texture swap;
    swap.loadFromFile("images/Swap.png");
    sf::Sprite swapSprite(swap);
    swapSprite.setPosition(914, 265);

    // Search User ID
    sf::Texture searchID;
    searchID.loadFromFile("images/SearchUserID.png");
    sf::Sprite searchIDSprite(searchID);
    searchIDSprite.setPosition(914, 190);

    // Overall Data
    sf::Texture searchOverall;
    searchOverall.loadFromFile("images/SearchAll.png");
    sf::Sprite searchOverallSprite(searchOverall);
    searchOverallSprite.setPosition(618, 190);

    // Search By Major
    sf::Texture searchMajor;
    searchMajor.loadFromFile("images/SearchByMajor.png");
    sf::Sprite searchMajorSprite(searchMajor);
    searchMajorSprite.setPosition(914, 190);

    // Search By College
    sf::Texture searchCollege;
    searchCollege.loadFromFile("images/SearchByCollege.png");
    sf::Sprite searchCollegeSprite(searchCollege);
    searchCollegeSprite.setPosition(618, 265);

    // Search By College & Major
    sf::Texture searchBoth;
    searchBoth.loadFromFile("images/CollegeAndMajor.png");
    sf::Sprite searchBothSprite(searchBoth);
    searchBothSprite.setPosition(914, 265);

    // Search Bar
    sf::Texture searchBar;
    searchBar.loadFromFile("images/SearchBar.png");
    sf::Sprite searchBarSprite(searchBar);
    searchBarSprite.setPosition(618, 190);

    // Search Bar2
    sf::Texture searchBar2;
    searchBar2.loadFromFile("images/SearchBar.png");
    sf::Sprite searchBarSprite2(searchBar);
    searchBarSprite2.setPosition(618, 265);

    // Previous College
    sf::Texture prevCollege;
    prevCollege.loadFromFile("images/previous.png");
    sf::Sprite prevCollegeSprite(prevCollege);
    prevCollegeSprite.setPosition(618, 340);

    // Next College

    sf::Texture nextCollege;
    nextCollege.loadFromFile("images/next.png");
    sf::Sprite nextCollegeSprite(nextCollege);
    nextCollegeSprite.setPosition(1114, 340);

    // Previous Major
    sf::Texture prevMajor;
    prevMajor.loadFromFile("images/previous.png");
    sf::Sprite prevMajorSprite(prevMajor);
    prevMajorSprite.setPosition(618, 395);

    // Next Major
    sf::Texture nextMajor;
    nextMajor.loadFromFile("images/next.png");
    sf::Sprite nextMajorSprite(nextMajor);
    nextMajorSprite.setPosition(1114, 395);

    // Change College
    sf::Texture changeCollege;
    changeCollege.loadFromFile("images/SelectCollege.png");
    sf::Sprite changeCollegeSprite(changeCollege);
    changeCollegeSprite.setPosition(816, 340);

    // Change Major
    sf::Texture changeMajor;
    changeMajor.loadFromFile("images/SelectMajor.png");
    sf::Sprite changeMajorSprite(changeMajor);
    changeMajorSprite.setPosition(816, 395);

    // Loading font for printing statistics
    sf::Font font;
    font.loadFromFile("BebasNeue-Regular.ttf");

    // Iterators are used to create search bars
    auto collegesIterator = colleges.begin();
    auto majorIterator = majors.begin();
    auto idIterator = ids.begin();

    // Start the game loop
    string screenMode = "MAIN_MENU";
    sf::Event event{};
    bool secondClick = false;
    bool firstSearch = true;
    pair<double, Student> tempPair;
    while (window.isOpen())
    {
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            secondClick = false;
        }

        // Clear screen
        window.clear();

        // Draws sprites that should always show
        window.draw(backgroundSprite);
        window.draw(logoTextSprite);
        window.draw(logoSphereSprite);
        window.draw(descriptionSprite);
        window.draw(statsScreenSprite);

        logoSphereSprite.rotate(0.1f);

        // Draws current mode
        if (mode == "BFS") {
            window.draw(BFSSprite);
        }
        else if (mode == "DFS") {
            window.draw(DFSSprite);
        }

        // Main Menu Screen
        if (screenMode == "MAIN_MENU") {

            window.draw(salaryDataSprite);
            window.draw(exitProgramSprite);
            window.draw(internshipDataSprite);
            window.draw(gradDataSprite);
            window.draw(swapSprite);
            window.draw(searchIDSprite);

            printHeader(window, font, "STATISTICS");
            printSecondLine(window, font, "Select an option to begin!");

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        window.close();
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (mode == "BFS") {
                            mode = "DFS";
                        }
                        else if (mode == "DFS") {
                            mode = "BFS";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "SEARCH_ID_MENU";
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        screenMode = "SALARY_MENU";
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "GRADUATE_MENU";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "INTERNSHIP_MENU";
                    }
                }
            }

        }

        // Salary Menu Screen
        else if (screenMode == "SALARY_MENU") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchOverallSprite);
            window.draw(searchMajorSprite);
            window.draw(searchCollegeSprite);
            window.draw(searchBothSprite);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "SALARY_BOTH";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "SALARY_MAJOR";
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "SALARY_COLLEGE";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "SALARY_OVERALL";
                    }
                }
            }
        }

        // Internship Menu Screen
        else if (screenMode == "INTERNSHIP_MENU") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchOverallSprite);
            window.draw(searchMajorSprite);
            window.draw(searchCollegeSprite);
            window.draw(searchBothSprite);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "INTERNSHIPS_BOTH";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "INTERNSHIPS_MAJOR";
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "INTERNSHIPS_COLLEGE";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "INTERNSHIPS_OVERALL";
                    }
                }
            }
        }

        // Graduate Menu Screen
        else if (screenMode == "GRADUATE_MENU") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchOverallSprite);
            window.draw(searchMajorSprite);
            window.draw(searchCollegeSprite);
            window.draw(searchBothSprite);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "GRADUATE_BOTH";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "GRADUATE_MAJOR";
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        screenMode = "GRADUATE_COLLEGE";
                    }
                    if (sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 240) {
                        screenMode = "GRADUATE_OVERALL";
                    }
                }
            }
        }

        // Search ID Menu Screen
        else if (screenMode == "SEARCH_ID_MENU") {

            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, to_string(*idIterator));

            printHeader(window, font, "Student Name");

            if (mode == "BFS" && firstSearch) {
                tempPair = studentList.searchStudentIDBFS(*idIterator);
                firstSearch = false;
            }
            else if (mode == "DFS" && firstSearch) {
                tempPair = studentList.searchStudentIDDFS(*idIterator);
                firstSearch = false;
            }

            printSecondLine(window, font, tempPair.second.firstName + " " + tempPair.second.lastName);
            printThirdLine(window, font, "Searched in " + to_string(tempPair.first * 1000).substr(0, 5) + " milliseconds...");

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                        firstSearch = true;
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                        firstSearch = true;
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "MAIN_MENU";
                            firstSearch = true;
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                            firstSearch = true;
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                    if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                        auto tempIterator = idIterator;
                        tempIterator++;
                        if (tempIterator == ids.end()) {
                            idIterator = ids.begin();
                        }
                        else {
                            idIterator++;
                        }
                        firstSearch = true;
                    }
                }
                if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                    if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                        if (idIterator == ids.begin()) {
                            idIterator = ids.end();
                            idIterator++;
                        }
                        else {
                            idIterator--;
                        }
                        firstSearch = true;
                    }
                }
            }
        }

        // Search Overall Avg Salary Screen
        else if (screenMode == "SALARY_OVERALL") {
            window.draw(goBackSprite);
            window.draw(homeSprite);

            printHeader(window, font, "Average Overall Salary");

            string avgSalary;
            if (mode == "BFS") {
                avgSalary = "$" + to_string(studentList.getAverageSalaryBFS());
            }
            else if (mode == "DFS") {
                avgSalary = "$" + to_string(studentList.getAverageSalaryDFS());
            }

            printSecondLine(window, font, avgSalary);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
            }
        }

        // Search Salary By College Screen
        else if (screenMode == "SALARY_COLLEGE") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *collegesIterator);
            printHeader(window, font, "Average Salary");

            string avgSalary;
            if (mode == "BFS") {
                avgSalary = "$" + to_string(studentList.getUniversitySalaryBFS(*collegesIterator));
            }
            else if (mode == "DFS") {
                avgSalary = "$" + to_string(studentList.getUniversitySalaryDFS(*collegesIterator));
            }

            printSecondLine(window, font, avgSalary);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = collegesIterator;
                            tempIterator++;
                            if (tempIterator == colleges.end()) {
                                collegesIterator = colleges.begin();
                            }
                            else {
                                collegesIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (collegesIterator == colleges.begin()) {
                                collegesIterator = colleges.end();
                                collegesIterator++;
                            }
                            else {
                                collegesIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Salary By Major Screen
        else if (screenMode == "SALARY_MAJOR") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *majorIterator);
            printHeader(window, font, "Average Salary");

            string avgSalary;
            if (mode == "BFS") {
                avgSalary = "$" + to_string(studentList.getMajorSalaryBFS(*majorIterator));
            }
            else if (mode == "DFS") {
                avgSalary = "$" + to_string(studentList.getMajorSalaryDFS(*majorIterator));
            }

            printSecondLine(window, font, avgSalary);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = majorIterator;
                            tempIterator++;
                            if (tempIterator == majors.end()) {
                                majorIterator = majors.begin();
                            }
                            else {
                                majorIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (majorIterator == majors.begin()) {
                                majorIterator = majors.end();
                                majorIterator++;
                            }
                            else {
                                majorIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Salary By College & Major Screen
        else if (screenMode == "SALARY_BOTH") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(searchBarSprite2);
            window.draw(prevCollegeSprite);
            window.draw(nextCollegeSprite);
            window.draw(prevMajorSprite);
            window.draw(nextMajorSprite);
            window.draw(changeCollegeSprite);
            window.draw(changeMajorSprite);

            printSearchLine(window, font, *collegesIterator);
            printSearchLine2(window, font, *majorIterator);

            printHeader(window, font, "AVERAGE SALARY");
            string avgSalary = "$" + to_string(studentList.getAverageSalary(*collegesIterator, *majorIterator));
            printSecondLine(window, font, avgSalary);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 668) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (collegesIterator == colleges.begin()) {
                            collegesIterator = colleges.end();
                            collegesIterator++;
                        }
                        else {
                            collegesIterator--;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        if (majorIterator == majors.begin()) {
                            majorIterator = majors.end();
                            majorIterator++;
                        }
                        else {
                            majorIterator--;
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 1114 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        auto tempIterator = collegesIterator;
                        tempIterator++;
                        if (tempIterator == colleges.end()) {
                            collegesIterator = colleges.begin();
                        }
                        else {
                            collegesIterator++;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        auto tempIterator = majorIterator;
                        tempIterator++;
                        if (tempIterator == majors.end()) {
                            majorIterator = majors.begin();
                        }
                        else {
                            majorIterator++;
                        }
                    }
                }
            }
        }

        // Search Internships Overall Avg Screen
        else if (screenMode == "INTERNSHIPS_OVERALL") {
            window.draw(goBackSprite);
            window.draw(homeSprite);

            printHeader(window, font, "Average # Internships");

            string avgNumInternships;
            if (mode == "BFS") {
                avgNumInternships = to_string(studentList.getAvgInternshipsBFS()).substr(0, 5);
            }
            else if (mode == "DFS") {
                avgNumInternships = to_string(studentList.getAvgInternshipsDFS()).substr(0, 5);
            }

            printSecondLine(window, font, avgNumInternships);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "INTERNSHIP_MENU";
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
            }
        }

        // Search Internships By College Screen
        else if (screenMode == "INTERNSHIPS_COLLEGE") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *collegesIterator);
            printHeader(window, font, "Average # Internships");

            string avgNumInternships;
            if (mode == "BFS") {
                avgNumInternships = to_string(studentList.getUniversityAvgInternshipsBFS(*collegesIterator)).substr(0, 5);
            }
            else if (mode == "DFS") {
                avgNumInternships = to_string(studentList.getUniversityAvgInternshipsDFS(*collegesIterator)).substr(0, 5);
            }

            printSecondLine(window, font, avgNumInternships);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "INTERNSHIP_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = collegesIterator;
                            tempIterator++;
                            if (tempIterator == colleges.end()) {
                                collegesIterator = colleges.begin();
                            }
                            else {
                                collegesIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (collegesIterator == colleges.begin()) {
                                collegesIterator = colleges.end();
                                collegesIterator++;
                            }
                            else {
                                collegesIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Internships By Major Screen
        else if (screenMode == "INTERNSHIPS_MAJOR") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *majorIterator);
            printHeader(window, font, "Average # Internships");

            string avgNumInternships;
            if (mode == "BFS") {
                avgNumInternships = to_string(studentList.getMajorAvgInternshipsBFS(*majorIterator)).substr(0, 5);
            }
            else if (mode == "DFS") {
                avgNumInternships = to_string(studentList.getMajorAvgInternshipsDFS(*majorIterator)).substr(0, 5);
            }

            printSecondLine(window, font, avgNumInternships);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = majorIterator;
                            tempIterator++;
                            if (tempIterator == majors.end()) {
                                majorIterator = majors.begin();
                            }
                            else {
                                majorIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (majorIterator == majors.begin()) {
                                majorIterator = majors.end();
                                majorIterator++;
                            }
                            else {
                                majorIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Internships By College & Major Screen
        else if (screenMode == "INTERNSHIPS_BOTH") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(searchBarSprite2);
            window.draw(prevCollegeSprite);
            window.draw(nextCollegeSprite);
            window.draw(prevMajorSprite);
            window.draw(nextMajorSprite);
            window.draw(changeCollegeSprite);
            window.draw(changeMajorSprite);

            printSearchLine(window, font, *collegesIterator);
            printSearchLine2(window, font, *majorIterator);

            printHeader(window, font, "Average # Internships");
            string avgNumInternships = to_string(studentList.getAvgInternships(*collegesIterator, *majorIterator)).substr(0, 5);
            printSecondLine(window, font, avgNumInternships);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "INTERNSHIP_MENU";
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 668) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (collegesIterator == colleges.begin()) {
                            collegesIterator = colleges.end();
                            collegesIterator++;
                        }
                        else {
                            collegesIterator--;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        if (majorIterator == majors.begin()) {
                            majorIterator = majors.end();
                            majorIterator++;
                        }
                        else {
                            majorIterator--;
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 1114 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        auto tempIterator = collegesIterator;
                        tempIterator++;
                        if (tempIterator == colleges.end()) {
                            collegesIterator = colleges.begin();
                        }
                        else {
                            collegesIterator++;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        auto tempIterator = majorIterator;
                        tempIterator++;
                        if (tempIterator == majors.end()) {
                            majorIterator = majors.begin();
                        }
                        else {
                            majorIterator++;
                        }
                    }
                }
            }
        }

        // Search Overall Graduate Admissions Screen
        else if (screenMode == "GRADUATE_OVERALL") {
            window.draw(goBackSprite);
            window.draw(homeSprite);

            printHeader(window, font, "Overall Graduate Admissions Rate");

            string avgGradAdmissions;
            if (mode == "BFS") {
                avgGradAdmissions = to_string(studentList.getGradStatsBFS() * 100).substr(0, 5) + "%";
            }
            else if (mode == "DFS") {
                avgGradAdmissions = to_string(studentList.getGradStatsDFS() * 100).substr(0, 5) + "%";
            }

            printSecondLine(window, font, avgGradAdmissions);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "GRADUATE_MENU";
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
            }

        }

        // Search Graduate Stats By College Screen
        else if (screenMode == "GRADUATE_COLLEGE") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *collegesIterator);
            printHeader(window, font, "Graduate Admissions Rate");

            string avgGradAdmissions;
            if (mode == "BFS") {
                avgGradAdmissions = to_string(studentList.getUniversityGradStatsBFS(*collegesIterator) * 100).substr(0, 5) + "%";
            }
            else if (mode == "DFS") {
                avgGradAdmissions = to_string(studentList.getUniversityGradStatsDFS(*collegesIterator) * 100).substr(0, 5) + "%";
            }

            printSecondLine(window, font, avgGradAdmissions);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "GRADUATE_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = collegesIterator;
                            tempIterator++;
                            if (tempIterator == colleges.end()) {
                                collegesIterator = colleges.begin();
                            }
                            else {
                                collegesIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (collegesIterator == colleges.begin()) {
                                collegesIterator = colleges.end();
                                collegesIterator++;
                            }
                            else {
                                collegesIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Graduate Stats By Major Screen
        else if (screenMode == "GRADUATE_MAJOR") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(previousSprite);
            window.draw(nextSprite);

            printSearchLine(window, font, *majorIterator);
            printHeader(window, font, "Graduate Admissions Rate");

            string avgGradAdmissions;
            if (mode == "BFS") {
                avgGradAdmissions = to_string(studentList.getMajorAvgGradStatsBFS(*majorIterator) * 100).substr(0, 5) + "%";
            }
            else if (mode == "DFS") {
                avgGradAdmissions = to_string(studentList.getMajorAvgGradStatsDFS(*majorIterator) * 100).substr(0, 5) + "%";
            }

            printSecondLine(window, font, avgGradAdmissions);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "SALARY_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            auto tempIterator = majorIterator;
                            tempIterator++;
                            if (tempIterator == majors.end()) {
                                majorIterator = majors.begin();
                            }
                            else {
                                majorIterator++;
                            }
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                    if (sf::Mouse::getPosition(window).y >= 265 && sf::Mouse::getPosition(window).y <= 315) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            if (majorIterator == majors.begin()) {
                                majorIterator = majors.end();
                                majorIterator++;
                            }
                            else {
                                majorIterator--;
                            }
                        }
                    }
                }
            }
        }

        // Search Graduate Stats By College & Major Screen
        else if (screenMode == "GRADUATE_BOTH") {
            window.draw(goBackSprite);
            window.draw(homeSprite);
            window.draw(searchBarSprite);
            window.draw(searchBarSprite2);
            window.draw(prevCollegeSprite);
            window.draw(nextCollegeSprite);
            window.draw(prevMajorSprite);
            window.draw(nextMajorSprite);
            window.draw(changeCollegeSprite);
            window.draw(changeMajorSprite);

            printSearchLine(window, font, *collegesIterator);
            printSearchLine2(window, font, *majorIterator);

            printHeader(window, font, "Graduate Admissions Rate");
            string graduateAdmissionsRate = to_string(studentList.getGradStats(*collegesIterator, *majorIterator) * 100).substr(0, 5) + "%";
            printSecondLine(window, font, graduateAdmissionsRate);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !secondClick) {
                int mouseColumn = (sf::Mouse::getPosition(window).x);
                int mouseRow = (sf::Mouse::getPosition(window).y);
                secondClick = true;

                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "BFS") {
                        mode = "DFS";
                    }
                    else if (sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 165 && mode == "DFS") {
                        mode = "BFS";
                    }
                }

                if (sf::Mouse::getPosition(window).x >= 914 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 1014 && sf::Mouse::getPosition(window).x <= 1064) {
                            screenMode = "GRADUATE_MENU";
                        }
                    }
                }
                else if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 868) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (sf::Mouse::getPosition(window).x >= 729 && sf::Mouse::getPosition(window).x <= 779) {
                            screenMode = "MAIN_MENU";
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 618 && sf::Mouse::getPosition(window).x <= 668) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        if (collegesIterator == colleges.begin()) {
                            collegesIterator = colleges.end();
                            collegesIterator++;
                        }
                        else {
                            collegesIterator--;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        if (majorIterator == majors.begin()) {
                            majorIterator = majors.end();
                            majorIterator++;
                        }
                        else {
                            majorIterator--;
                        }
                    }
                }
                if (sf::Mouse::getPosition(window).x >= 1114 && sf::Mouse::getPosition(window).x <= 1164) {
                    if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390) {
                        auto tempIterator = collegesIterator;
                        tempIterator++;
                        if (tempIterator == colleges.end()) {
                            collegesIterator = colleges.begin();
                        }
                        else {
                            collegesIterator++;
                        }
                    }
                    else if (sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).y <= 445) {
                        auto tempIterator = majorIterator;
                        tempIterator++;
                        if (tempIterator == majors.end()) {
                            majorIterator = majors.begin();
                        }
                        else {
                            majorIterator++;
                        }
                    }
                }
            }
        }

        // Update the window
        window.display();

        // Close The Window
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
