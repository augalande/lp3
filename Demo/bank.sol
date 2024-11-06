// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract bank_sc {
    mapping(address=>uint) balances;

    function deposit() public payable{
        balances[msg.sender]=balances[msg.sender]+msg.value;
    }

    function withdraw(uint amount) public{
        require(amount<=balances[msg.sender],"Insufficent Funds");
        balances[msg.sender]=balances[msg.sender]-amount;
        payable(msg.sender).transfer(amount);
    }

    function checkBalance() public view returns(uint){
        return balances[msg.sender];
    }
}
