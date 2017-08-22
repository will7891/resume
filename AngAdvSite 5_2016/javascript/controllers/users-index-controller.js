angular.module('NoteWrangler')
 .controller('UsersIndexController', ['$http', '$scope', function ($http, $scope) {
     $http({ method: "GET", url: "data/users.json" }).success(function (data) {
         $scope.users = data;
     }).error(function (error) { alert("error"); });
 } ]);