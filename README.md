# Conflict Based Search
Реализация алгоритма многоагентного поиска пути на базе Conflict Based Search

## Требования
### Linux
- Git 2.7.4 или выше
- CMake 3.2 или выше;
- GCC 4.9 или выше

### Mac
- Git 2.23.0 или выше
- CMake 3.2 или выше;
- Apple LLVM version 10.0.0 (clang-1000.11.45.5) или выше;

### Windows
- Git 2.23.0 или выше
- CMake 3.2 или выше;

## Начало работы
Cоздайте ответвление (fork) этого репозитория в свой GitHub аккаунт. Загрузите содержимое полученного репозитория, либо клонируйте его в нужную вам директорию.
```bash
git https://github.com/dpaleyev/PathPlanningProject.git
```

или (с помощью ssh)

```bash
git@github.com:dpaleyev/PathPlanningProject.git
```

или просто скачать архив с файлами

### Сборка и запуск

Сборку проекта возможно осуществить используя CMake.

При использовании CMake сборка и запуск может производиться как из командной строки, так и при помощи различных IDE (например JetBrains CLion). Ниже приведены скрипты сборки и запуска с использованием командной строки.

### Linux и Mac
Release сборка:
```bash
cd PathPlanningProject
cd Build
cd Release
cmake ../../ -DCMAKE_BUILD_TYPE="Release"
make
make install
```

Debug сборка:
```bash
cd PathPlanningProject
cd Build
cd Debug
cmake ../../ -DCMAKE_BUILD_TYPE="Debug"
make
make install
```

Запуск:
```bash
cd ../../Bin/{Debug|Release}/
./PathPlanning ../../Examples/example.xml
```
Результат запуска:

![cmake_run](./Images/cmake1.png)

### Windows
Release сборка:
```cmd
cd PathPlanningProject
cd Build
cd Release
set PATH
cmake ../../ -DCMAKE_BUILD_TYPE="Release" -G "MinGW Makefiles"
mingw32-make
mingw32-make install
```

Debug сборка:
```cmd
cd PathPlanningProject
cd Build
cd Debug
set PATH
cmake ../../ -DCMAKE_BUILD_TYPE="Debug" -G "MinGW Makefiles"
mingw32-make
mingw32-make install
```

Запуск:
```cmd
cd ../../Bin/{Debug|Release}/
PathPlanning.exe ../../Examples/example.xml
```

## Формат данных
Примеры входных и выходных файлов можно посмотреть в папке `Examples`

Входной файл содержится в теге `root`, в котором расположены следующие теги:
+ `map` &mdash; обязательный тег, содержащий основную информацию о задаче
    + `width`, `height` &mdash; размеры карты
    + `cellsize` &mdash; размер одной клетки
    + `startx`, `starty` &mdash; координаты начальной клетки для каждого агента по очереди в тегах `agent`
    + `finishx`, `finishy` &mdash; координаты конечной клетки для каждого агента по очереди в тегах `agent`
    + `grid` &mdash; содержит поле: `height` тегов `row`, в каждом из которых `width` нулей или единиц через пробел, причем нули означают свободную клетку, а единицы &mdash; занятую
+ `algorithm`
    + `searchtype` &mdash; алгоритм поиска: `astar`
    + `metrictype` &mdash; эвристика для оценки расстояния (`x`, `y` &mdash; расстояние до цели по горизонтали и вертикали соответственно)
        + `euclidean` &mdash; `sqrt(x * x + y * y)`
        + `manhattan` &mdash; `abs(x) + abs(y)`
        + `chebyshev` &mdash; `max(abs(x), abs(y))`
        + `diagonal` &mdash; `min(x, y) * (sqrt(2) - 1) + max(x, y)`
    + `hweight` &mdash; вес эвристики при подсчете `f` вершины
    + `allowdiagonal` &mdash; разрешено ли ходить по диагонали: `true` или `false`
    + `cutcorners` &mdash; разрешено ли ходить по диагонали, если с одной стороны стена: `true` или `false`
    + `allowsqueeze` &mdash; разрешено ли ходить по диагонали, если с обеих сторон стены: `true` или `false`
    + `prioratizeconflicts` &mdash; включено ли использование улучшения приоритезации конфликов в CBS: `true` или `false`
    + `bypass` &mdash; включено ли использование улучшения приоритезации конфликов в CBS: `true` или `false`
    + `corridorsymmetry` &mdash; включено ли использование улучшения распознавания конфликов в коридорах в CBS: `true` или `false`
    + `targetsymmetry` &mdash; включено ли использование улучшения распознавания конфликтов в конечных точках в CBS: `true` или `false`
      
+ `options`
    + `loglevel` &mdash; уровень логирования, каждый следующий включает всю информацию предыдущего
        + `0` &mdash; ничего
        + `0.5` &mdash; только тег `summary` (подробнее в формате выходного файла)
        + `1` &mdash; путь на поле и в форматах `hplevel` и `lplevel`
        + `1.5` &mdash; тег `lowlevel`, в который записываются списки `OPEN` и `CLOSED` в конце работы алгоритма
        + `2` &mdash; в тег `lowlevel` списки `OPEN` и `CLOSED` записываются на каждом шаге алгоритма
    + `logpath`
    + `logfilename`


## Визуализация
Визуализация происходит с помощью Python скрипта `visualizer.py`

После запуска передается путь до лог файла и автоматические начинается визуализация

### Пример:

![Alt Text](/Images/visualizer_example.gif)

## Контакты
**Яковлев Константин Сергеевич**
- kyakovlev@hse.ru
- [Сайт НИУ ВШЭ](https://www.hse.ru/staff/yakovlev-ks)
- Telegram: @KonstantinYakovlev
  
**Дергачев Степан**
- sadergachev@edu.hse.ru
- Telegram: @haiot4105
