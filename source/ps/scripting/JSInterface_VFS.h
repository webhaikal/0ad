// JSInterface_VFS.h
//
// The JavaScript wrapper around useful snippets of the VFS

#ifndef JSI_VFS_INCLUDED
#define JSI_VFS_INCLUDED

#include "scripting/ScriptingHost.h"

// [KEEP IN SYNC WITH TDD AND WIKI]

namespace JSI_VFS
{
	// Return an array of pathname strings, one for each matching entry in the
	// specified directory.
	//
	// array_of_filenames = buildFileList(start_path [, filter_string [, recursive ] ]);
	//   directory: VFS path
	//   filter_string: default "" matches everything; otherwise, see vfs_next_dirent.
	//   recurse: should subdirectories be included in the search? default false.
	//
	// note: full pathnames of each file/subdirectory are returned,
	// ready for use as a "filename" for the other functions.
	JSBool BuildFileList( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );

	// Return timestamp of the last modification to the specified file.
	//
	// seconds_since_1970 = getFileMTime(filename);
	//   filename: VFS filename (may include path)
	JSBool GetFileMTime( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );

	// Return current size of file.
	//
	// size = getFileSize(filename);
	//   filename: VFS filename (may include path)
	JSBool GetFileSize( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );

	// Return file contents in a string.
	//
	// contents_string = readFile(filename);
	//   filename: VFS filename (may include path)
	JSBool ReadFile( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );

	// Return file contents as an array of lines.
	//
	// array_of_strings = readFileLines(filename);
	//   filename: VFS filename (may include path)
	JSBool ReadFileLines( JSContext* cx, JSObject* obj, uintN argc, jsval* argv, jsval* rval );
};

#endif
