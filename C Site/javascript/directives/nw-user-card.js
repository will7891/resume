angular.module("NoteWrangler").directive("nwUserCard", function () {
    return {
        restrict: 'E',
        templateUrl: 'templates/directives/nw-user-card.html',
        controller: function ($scope) {
            $scope.month = 'May 5th 2016';
        },
        scope: {
            name: "=", // 2-way binding
            bio: "=",
            ident: "="
        },
        link: function (scope, element) {
            var ID = "#user" + scope.ident;
            $('body').on("click", ID, function () {
                var item = ID + " p";
                if ($(item).hasClass("hidden")) {
                    $(item).removeClass("hidden");
                    $(item).addClass("shown");
                }
                else {
                    $(item).removeClass("shown");
                    $(item).addClass("hidden");
                }
            });
        } // link
    }; // return
});// nwUserCard