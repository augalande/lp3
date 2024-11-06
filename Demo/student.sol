// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract student_sc{

    struct Student{
        uint rollno;
        string name;
    }

    Student[] public students;
    mapping (uint=>Student) studentsMapping;

    function addStudent(uint rollno,string memory name) public{
        students.push(Student(rollno,name));
        studentsMapping[rollno]=Student(rollno,name);
    }

    function getStudent(uint rollno) public view returns (uint ,string memory){
        for(uint i=0;i<students.length;i++)
        {
            if(students[i].rollno==rollno)
            {
                return (students[i].rollno,students[i].name);
            }
        }
        revert("Not Found");
    }

    function totalStudents() public view returns (uint){
        return students.length;
    }
}