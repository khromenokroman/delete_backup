#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>

bool check_input(int argc) //проверим чтоб не было много параметров
{
    if (argc < 3)
        return false;
    else if (argc > 3)
        return false;
    else
        return true;
}

int main(int argc, char *argv[])
{
    if (!check_input(argc)) //скажем что не так
    {
        std::cout << "!!! ERROR !!! parameters...\n";
        return -1;
    }
    std::string PATH = argv[1];     // путь до папки в которой надо производить очистку
    int DEPTH = std::stoi(argv[2]); // глубина очистки

    namespace fs = std::filesystem;                                         // сделали короче имя
    std::vector<std::string> vec_path;                                      // массив адресов
    std::filesystem::path path{PATH};                                       // путь до попки в которой надо произвести очистку
    for (auto const &dir_entry : std::filesystem::directory_iterator{path}) // добавим адреса на файлы в папке в массив
    {
        if (dir_entry.is_directory()) // папки пропустим
        {
            continue;
        }
        vec_path.push_back(dir_entry.path());
    }
    std::vector<std::string>::iterator it = vec_path.begin();                 // создадим итератор
    std::sort(vec_path.begin(), vec_path.end(), std::greater<std::string>()); // отсортируем массив чтоб в начале были свежие
    int counter = 1;
    if (vec_path.size() <= DEPTH)
    {
        std::cout << "There are fewer files in the directory than " << DEPTH << " ..." << std::endl;
    }
    else
    {
        for (it; it != vec_path.end(); it++) // первые DEPTH не трогаем, остально еудаляем
        {
            if (counter > DEPTH)
            {
                std::cout << "Delete file -- " << *it << std::endl;
                fs::remove(*it);
            }
            counter++;
        }
    }
    return 0;
}