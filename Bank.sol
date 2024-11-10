// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract Bank {

    // Mapping to keep track of balances for each user
    mapping(address => uint256) private balances;


    // Event to log deposits and withdrawals
    event Deposit(address indexed user, uint256 amount);
    event Withdrawal(address indexed user, uint256 amount);

    // Function to deposit money into the bank
    function deposit(uint256 _amount) public payable {
        require(_amount > 0, "Deposit amount must be greater than zero");
        balances[msg.sender] += _amount;
        emit Deposit(msg.sender, _amount);
    }
    
    // Function to withdraw money from the bank
    function withdraw(uint256 _amount) public {
        require(_amount > 0, "Withdraw amount must be greater than zero");
        require(balances[msg.sender] >= _amount, "Insufficient balance");
        
        balances[msg.sender] -= _amount;
        
        emit Withdrawal(msg.sender, _amount);
    }

    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}