// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract StudentData {

    struct Course {
        uint id;
        string name;
    }

    struct Student {
        uint id;
        string name;
        uint256 balance;
        uint courseIds;  
    }

    Course[] public courses;

    mapping(address => Student) private students;

    address private owner;

    event Registered(address indexed student, uint id, string name);
    event AddedCourse(address indexed admin, uint courseId, string courseName);
    event Deposited(address indexed student, uint256 amount);
    event FallbackTriggered(address sender, uint256 value, bytes data);

    modifier onlyOwner() {
        require(msg.sender == owner, "You are not the owner");
        _;
    }

    constructor() {
        owner = msg.sender;
    }

    function registerStudent(uint _id, string memory _name, uint _courseId) public {
        require(bytes(_name).length > 0, "Name cannot be empty");
        require(students[msg.sender].id == 0, "Student already registered");

        students[msg.sender] = Student({
            id: _id,
            name: _name,
            balance: 0,
            courseIds: _courseId
        });

        emit Registered(msg.sender, _id, _name);
    }

    function deposit() public payable {
        require(msg.value > 0, "Must send some Ether to deposit");
        require(students[msg.sender].id != 0, "Student not registered");

        students[msg.sender].balance += msg.value;
        emit Deposited(msg.sender, msg.value);
    }

    function addCourse(string memory _courseName) public onlyOwner {
        uint courseId = courses.length;
        courses.push(Course({
            id: courseId,
            name: _courseName
        }));

        emit AddedCourse(msg.sender, courseId, _courseName);
    }

    function getStudentInfo() public view returns (
        uint id, 
        string memory name, 
        uint256 balance, 
        uint courseIds
    ) {
        Student storage student = students[msg.sender];
        require(student.id != 0, "Student not registered");

        return (student.id, student.name, student.balance, student.courseIds);
    }

    function getCourses() public view returns (Course[] memory) {
        return courses;
    }

    // Receive function to accept Ether and log deposit events
    receive() external payable {
        emit Deposited(msg.sender, msg.value);
    }

    // Fallback function to handle unexpected transactions or calls with data
    fallback() external payable {
        emit FallbackTriggered(msg.sender, msg.value, msg.data);
    }
}
