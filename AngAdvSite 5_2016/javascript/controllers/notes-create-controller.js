angular.module('NoteWrangler')
 .controller('NoteCreateController', ['$http', function ($http) {
     var controller = this;
     this.saveNote = function (note) {
         controller.errors = null;
         $http({ method: "POST", url: "data/notes.json", data: note })
           .error(function (note) {
              controller.errors = note;
         });
    };
 } ]);
