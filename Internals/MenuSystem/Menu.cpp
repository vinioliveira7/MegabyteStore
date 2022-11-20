//
// Created by luanr on 26/10/2022.
//

#include "Menu.h"

namespace MenuSystem {
    Menu::Menu(std::string header) {
        this->header = header;
    }
    Menu::Menu(string header, string content) {
        this->header = header;
        this->content = content;
    }

    void Menu::PrintHeaderContent() {
        cout << header << endl;

        if(!content.empty())
            cout << content << endl;
    }
    void Menu::PrintOptions() {
        for (MenuInfoItem menuInfoItem : menuMapping) {
            string menuOption =  "[ " + std::to_string(menuInfoItem.getOptionNumber()) + " ] - " +
                    menuInfoItem.getText();
            cout << menuOption << endl;
        }
    }
    void Menu::RunMenu(MenuPredictor menuPredictor) {
        LineReader lineReader(ReaderOptions("Digite uma value válido", false));
        PrintHeaderContent();

        do {
            int choice;

            PrintOptions();

            choice = lineReader.ReadInt("Escolha uma opção: ");

            std::function<void()> menuCommand = nullptr;
            for(MenuInfoItem menuInfoItem : menuMapping) {
                if(menuInfoItem.getOptionNumber() == choice)
                    menuCommand = menuInfoItem.getAction();
            }

            if(menuCommand == nullptr) continue;

            menuCommand();

            running = menuPredictor();
        }
        while (running);
    }
    void Menu::RunMenu() {
        LineReader lineReader(ReaderOptions("Digite uma value válido", false));
        PrintHeaderContent();

        while (running) {
            int choice;

            PrintOptions();

            choice = lineReader.ReadInt("Escolha uma opção: ");

            std::function<void()> menuCommand = nullptr;
            for(MenuInfoItem menuInfoItem : menuMapping) {
                if(menuInfoItem.getOptionNumber() == choice)
                    menuCommand = menuInfoItem.getAction();
            }

            if(menuCommand == nullptr) continue;

            menuCommand();
        }
    }

    void Menu::InjectCommandOnEscapeOption() {
        MenuInfoItem menuInfo = (menuMapping)[escapeOptionIndex];
        menuInfo.setAction([this]() {
            this->Stop();
        });
    }

    void Menu::AddMenu(MenuInfoItem menuInfo) {
        menuMapping.push_back(menuInfo);
    }

    void Menu::AddEscapeOption(MenuInfoItem menuInfo) {
        if(!menuInfo.isEscapeOption())
            throw std::invalid_argument("MenuInfoItem is not a escape option");

        escapeOptionIndex = static_cast<int>(menuMapping.size());
        menuMapping.push_back(menuInfo);
        InjectCommandOnEscapeOption();
    }

    void Menu::SetHeader(std::string header) {
        this->header = header;
    }
    void Menu::SetContent(string content) {
        this->content = content;
    }

    void Menu::Start(MenuPredictor menuPredictor) {
        RunMenu(menuPredictor);
    }
    void Menu::Start() {
        RunMenu();
    }

    void Menu::Stop() {
        running = false;
    }

} // MenuSystem