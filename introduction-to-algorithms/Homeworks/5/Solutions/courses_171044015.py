
class Course:
    def __init__(self, name, start, finish):
        self.name = name
        self.start = start
        self.finish = finish

    def __lt__(self, other):
        return self.finish < other.finish

def createCoursesArray(name, start, finish):
    coursesArray = []

    for i in range(len(finish)):
        coursesArray.append(Course(name[i], start[i], finish[i]))

    coursesArray.sort(reverse = False)

    return coursesArray

def findMaximumNumberOfCourses(name, start, finish):
    coursesArray = createCoursesArray(name, start, finish)

    j = 0
    count = 1
    maximumCoursesArray = []
    maximumCoursesArray.append(coursesArray[0])

    for i in range(len(coursesArray)):
        if coursesArray[i].start >= coursesArray[j].finish:
            maximumCoursesArray.append(coursesArray[i])
            count += 1
            j = i

    printCourseName(maximumCoursesArray)

    return count

def printCourseName(courseArray):
    for i in range(len(courseArray)):
        print('%d)' % (i + 1), courseArray[i].name)


if __name__ == '__main__':
    s = [1, 3, 0, 5, 8, 5]
    f = [2, 4, 6, 7, 9, 9]
    n = ["English", "Mathematics", "Physics", "Chemistry", "Biology", "Geography"]

    print('Maximum number of courses:', findMaximumNumberOfCourses(n, s, f))
