//(function () {    
    angular.module('NoteWrangler', ['ngRoute'])
      .config(['$routeProvider', function ($routeProvider) {
        $routeProvider
          .when('/', { redirectTo: '/home' })
          .when('/home', {
              templateUrl: 'templates/pages/notes/index.html',
              controller: 'NotesIndexController'
          })
          .when('/about', {
              templateUrl: 'templates/pages/notes/About.html',
              controller: 'SiteAboutController'
          })
          .when ('/services', {
              templateUrl: 'templates/pages/notes/index.html',
              controller: 'NotesIndexController'
          })
          .when('/contact', {
              templateUrl: 'templates/pages/users/index.html',
              controller: 'UsersIndexController'
          })
          .when('/notes/:id', {
              tempalteUrl: 'templates/pages/notes/show.html',
              controller: 'NotesShowController'
          })
          .otherwise({ redirectTo: '/' });
      } ]);
