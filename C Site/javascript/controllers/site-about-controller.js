angular.module('NoteWrangler')
.controller('SiteAboutController', ['$http', '$scope', function ($http, $scope) {
    $http({ method: "GET", url: "data/therapies.json" }).success(function (data) {
        $scope.therapies = data;
    }).error(function (error) {
        alert("Error in grabbing therapies\n" + error);
    });
} ]);