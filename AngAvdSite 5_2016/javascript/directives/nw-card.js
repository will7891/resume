angular.module("NoteWrangler").directive("nwCard", function () {
    return {
        restrict: 'E',
        templateUrl: 'templates/directives/nw-card.html',
        controller: function ($scope) {
            $scope.month = 'May 5th 2016';
        },
        scope: {
            header: "=", // 2-way binding
            desc: "="   
        }
    };
});