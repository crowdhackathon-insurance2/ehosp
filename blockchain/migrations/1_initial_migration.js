var Migrations = artifacts.require("./Migrations.sol");
var HealthData = artifacts.require("./HealthData.sol");

module.exports = function(deployer) {
  deployer.deploy(Migrations);
  deployer.deploy(HealthData);
};
