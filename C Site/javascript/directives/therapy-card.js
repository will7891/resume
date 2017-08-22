angular.module("NoteWrangler").directive("therapyCard", function () {
    return {
        restrict: 'E',
        templateUrl: 'templates/directives/therapy-card.html',
        controller: function ($scope) {
        },
        scope: {
            identity: "=", // 2-way binding
            type: "="
        }
    };
});