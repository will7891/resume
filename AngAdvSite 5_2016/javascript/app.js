//(function () {    
    angular.module('NoteWrangler', ['ngRoute'])
      .config(['$routeProvider', function ($routeProvider) {
        $routeProvider
          .when('/', { redirectTo: '/notes' })
          .when('/notes', {
              templateUrl: 'templates/pages/notes/index.html',
              controller: 'NotesIndexController',
              //controllerAs: 'indexController' // VERSION 1, [VERSION 2 is w/o this line]
          })
          .when('/users', {
              templateUrl: 'templates/pages/users/index.html',
              controller: 'UsersIndexController',
              //controllerAs: 'UsersCtrlr'
          })
          .when('/notes/:id', {
              templateUrl: 'templates/pages/notes/show.html',
              controller: 'NotesShowController',
              controllerAs: 'showController'
          })
          .otherwise({ redirectTo: '/' });
      } ]);
