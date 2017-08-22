angular.module('NoteWrangler')
 .controller('NotesShowController', ['$http', '$routeParams', function ($http, $routeParams) {
     var controller = this;
     $http({ method: "GET", url: 'data/note' + $routeParams.id + '.json' }).success(function (data) {
         controller.note = data;
         //alert(controller.note.title);
     }).error(function (error) { alert(error); });
 } ]);