/* VERSION 2 */
angular.module('NoteWrangler')
 .controller('NotesIndexController', ['$http', '$scope', function ($http, $scope) {
     $http({ method: "GET", url: "data/notes.json" }).success(function (data) {
         $scope.notes = data;
     }).error(function (error) { alert("error"); });
 } ]);

/*  VERSION 1
angular.module('NoteWrangler')
 .controller('NotesIndexController', ['$http', '$scope', function ($http, $scope) {
     var controller = this;
     $http({ method: "GET", url: "data/notes.json" }).success(function (data) {
        controller.notes = data;
     }).error(function(error){alert("error");});
 } ]);
 */