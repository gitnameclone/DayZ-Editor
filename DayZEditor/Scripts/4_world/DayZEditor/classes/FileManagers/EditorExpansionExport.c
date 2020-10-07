

class EditorExpansionFile: EditorFileType
{
	
	override EditorSaveData Import(FileHandle handle, ImportSettings settings) 
	{
		EditorSaveData save_data = new EditorSaveData();
	
        string line;
        int line_size = FGets(handle, line);
		while (line_size > 1) {
			
			TStringArray tokens = {};
	        line.Split("|", tokens); 
	        save_data.EditorObjects.InsertData(EditorObjectData.Create(tokens[0], tokens[1].ToVector(), tokens[2].ToVector(), EditorObjectFlags.ALL));
			
			line_size = FGets(handle, line);
		}        

		return save_data;
	}
	
	override void Export(EditorSaveData data, FileHandle handle, ExportSettings settings)
	{		
		foreach (EditorObjectData editor_object: data.EditorObjects) {
			// Land_Construction_House2|13108.842773 10.015385 6931.083984|-101.999985 0.000000 0.000000
			string line = string.Format("%1|%2 %3 %4|%5 %6 %7", editor_object.Type, editor_object.Position[0], editor_object.Position[1], editor_object.Position[2], editor_object.Orientation[0], editor_object.Orientation[1], editor_object.Orientation[2]);
			FPrintln(handle, line);
		}		
	}
	
}
